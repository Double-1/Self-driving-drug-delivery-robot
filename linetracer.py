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

senario = [0b1000,0b1100,0b0100,0b0000,0b0010,0b0011,0b0001]
def setMotorContorl(PWM, IN1, IN2, speed, stat):

    PWM.ChangeDutyCycle(speed)
    print("Current speed is", speed)

    if stat == FORWARD:
        print("FOWARD")
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
        setMotorContorl(pwm_R_A, _IN1_R, _IN2_R, speed, stat)
    elif ch == CH4:
        setMotorContorl(pwm_R_B, _IN3_R, _IN4_R, speed, stat)
    else:
        setMotorContorl(pwmB, _IN3, _IN4, speed, stat)

def checkSenario(state):

   #0b1000
   if state == senario[0]:
        setMotor(CH1,0,STOP)
        setMotor(CH2,40,FORWARD)
        setMotor(CH3,40,FORWARD)
        setMotor(CH4,0,STOP)
        time.sleep(2)

   #0b1100
   elif state == senario[1]:
        setMotor(CH1,30,FORWARD)
        setMotor(CH2,35,FORWARD)
        setMotor(CH3,35,FORWARD)
        setMotor(CH4,30,FORWARD)
        time.sleep(2)
   #0b0100
   elif state == senario[2]:
        setMotor(CH1,40,FORWARD)
        setMotor(CH2,30,FORWARD)
        setMotor(CH3,30,FORWARD)
        setMotor(CH4,40,FORWARD)
        time.sleep(2)

   #0b0000
   elif state == senario[3]:
        setMotor(CH1,40,FORWARD)
        setMotor(CH2,40,FORWARD)
        setMotor(CH3,40,FORWARD)
        setMotor(CH4,40,FORWARD)
        time.sleep(2)

   #0b0010
   elif state == senario[4]:
        setMotor(CH1,30,FORWARD)
        setMotor(CH2,40,FORWARD)
        setMotor(CH3,40,FORWARD)
        setMotor(CH4,30,FORWARD)
        time.sleep(2)

   #0b0011
   elif state == senario[5]:
        setMotor(CH1,30,FORWARD)
        setMotor(CH2,35,FORWARD)
        setMotor(CH3,35,FORWARD)
        setMotor(CH4,30,FORWARD)
        time.sleep(2)

   #0b0001
   elif state == senario[6]:
        setMotor(CH1,40,FORWARD)
        setMotor(CH2,0 ,FORWARD)
        setMotor(CH3,0 ,FORWARD)
        setMotor(CH4,40,FORWARD)
        time.sleep(2)

   #STOP
   else:
        setMotor(CH1, 0, STOP)
        setMotor(CH2, 0, STOP)
        setMotor(CH3, 0, STOP)
        setMotor(CH4, 0, STOP)
        time.sleep(2)

print("====START====")

pwmA = setPinConfig(_ENA, _IN1, _IN2)
pwmB = setPinConfig(_ENB, _IN3, _IN4)
pwm_R_A = setPinConfig(_EN_R_A, _IN1_R, _IN2_R)
pwm_R_B = setPinConfig(_EN_R_B, _IN3_R, _IN4_R)

setMotor(CH1, 0, STOP)
setMotor(CH2, 0, STOP)
setMotor(CH3, 0, STOP)
setMotor(CH4, 0, STOP)

GPIO.cleanup()

print("====END====")

