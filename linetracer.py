import RPi.GPIO as GPIO
import time

STOP = 0
FORWARD = 1
BACKWARD = 2

CH1 = 0
CH2 = 1
CH3 = 2
CH4 = 3

OUTPUT = 1
INPUT = 0

HIGH = 1
LOW = 0

_ENA = 4
_IN1 = 3
_IN2 = 2

_ENB = 22
_IN3 = 17
_IN4 = 27

_EN_R_A = 18
_IN1_R = 14
_IN2_R = 15

_EN_R_B = 11
_IN3_R = 10
_IN4_R = 9

LED1 = 13
LED2 = 0
LED3 = 6
LED4 = 5

senario = [0b0111,0b1100,0b1011,0b1111,0b1101,0b0011,0b1110,0b1001]

def setLEDConfig(led1,led2,led3,led4):
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(led1, GPIO.IN)
    GPIO.setup(led2, GPIO.IN)
    GPIO.setup(led3, GPIO.IN)
    GPIO.setup(led4, GPIO.IN)

def setPinConfig(ENA, IN1, IN2):
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(ENA, GPIO.OUT)
    GPIO.setup(IN1, GPIO.OUT)
    pwm = GPIO.PWM(ENA, 500)
    pwm.start(0)
    return pwm

def setMotorContorl(PWM, IN1, IN2, speed, stat):

    PWM.ChangeDutyCycle(speed)
    print("Current speed is", speed)

    if stat == FORWARD:
        GPIO.output(IN1, HIGH)
        GPIO.output(IN2, LOW)

    elif stat == BACKWARD:
        print("BACKWARD")
        GPIO.output(IN1, LOW)
        GPIO.output(IN2, HIGH)

    elif stat == STOP:
        print("STOP")
        GPIO.output(IN1, LOW)
        GPIO.output(IN2, LOW)

    else:
        print("STOP")
        GPIO.output(IN1, LOW)
        GPIO.output(IN2, LOW)

def setMotor(ch, speed, stat):
    if ch == CH1:
        setMotorContorl(pwmA, _IN1,_IN2, speed, stat)
    elif ch == CH3:
        #print("CH3")
        setMotorContorl(pwm_R_A, _IN1_R, _IN2_R, speed, stat)
    elif ch == CH4:
        setMotorContorl(pwm_R_B, _IN3_R, _IN4_R, speed, stat)
    else:
        setMotorContorl(pwmB, _IN3, _IN4, speed, stat)

def checkSenario(state):

   #0b0111
   if state == senario[0]:
        setMotor(CH1,80,FORWARD)
        setMotor(CH3,60,BACKWARD)
        #time.sleep(0.5)
        setMotor(CH2,60,BACKWARD)
        setMotor(CH4,80,FORWARD)
        time.sleep(1)

   #0b1100
   elif state == senario[1]:
        setMotor(CH1,55,BACKWARD)        
	setMotor(CH3,70,FORWARD)
        setMotor(CH2,70,FORWARD)
        setMotor(CH4,55,BACKWARD)
        time.sleep(1)

   #0b1011
   elif state == senario[2]:
        setMotor(CH1,70,FORWARD)
        setMotor(CH3,55,FORWARD)
        setMotor(CH2,55,FORWARD)
        setMotor(CH4,70,FORWARD)
        time.sleep(1)

   #0b1111
   elif state == senario[3]:
        setMotor(CH1,95,FORWARD)
        setMotor(CH3,100,FORWARD)
        setMotor(CH4,100,FORWARD)
        setMotor(CH2,95,FORWARD)
        time.sleep(1)

   #0b1101
 elif state == senario[4]:
        setMotor(CH1,95,FORWARD)
        setMotor(CH3,90,FORWARD)
        setMotor(CH2,90,FORWARD)
        setMotor(CH4,95,FORWARD)
        time.sleep(1)

   #0b0011
   elif state == senario[5]:
        setMotor(CH1,100,FORWARD)
        setMotor(CH3,70,BACKWARD)
        setMotor(CH2,70,BACKWARD)
        setMotor(CH4,100,FORWARD)
        time.sleep(1)

   #0b1110
   elif state == senario[6]:
        setMotor(CH1,80,BACKWARD)
        setMotor(CH3,100,FORWARD)
        setMotor(CH2,100,FORWARD)
        setMotor(CH4,80,BACKWARD)
        time.sleep(1)

   #0b1001
   elif state == senario[7]:
        setMotor(CH1,80,FORWARD)
        setMotor(CH3,80,FORWARD)
        setMotor(CH2,80,FORWARD)
        setMotor(CH4,80,FORWARD)
        time.sleep(1)
   #STOP
   else:
        setMotor(CH1, 0, STOP)
        setMotor(CH3, 0, STOP)
        setMotor(CH2, 0, STOP)
        setMotor(CH4, 0, STOP)
        time.sleep(1)

print("====START====")
#GPIO.cleanup()

try :
        pwmA = setPinConfig(_ENA, _IN1, _IN2)
        pwmB = setPinConfig(_ENB, _IN3, _IN4)
        pwm_R_A = setPinConfig(_EN_R_A, _IN1_R, _IN2_R)
        pwm_R_B = setPinConfig(_EN_R_B, _IN3_R, _IN4_R)
        setLEDConfig(LED1,LED2,LED3,LED4)

        while True :
                time.sleep(0.5)
                led1_out = GPIO.input(LED1)
                led2_out = GPIO.input(LED2)
                led3_out = GPIO.input(LED3)
                led4_out = GPIO.input(LED4)
                print(led1_out, led2_out, led3_out, led4_out)

                senario_state = led1_out*8 + led2_out*4 + led$
                print(senario_state)

                checkSenario(senario_state)

except:
        print("exception")
        GPIO.cleanup()
#setMotor(CH1, 0, STOP)
#setMotor(CH2, 0, STOP)
#setMotor(CH3, 0, STOP)
#setMotor(CH4, 0, STOP)

#GPIO.cleanup()

print("====END====")
