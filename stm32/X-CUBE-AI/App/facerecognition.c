/**
  ******************************************************************************
  * @file    facerecognition.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sun Jan  3 04:46:43 2021
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "facerecognition.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "layers.h"



#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#define AI_TOOLS_VERSION_MAJOR 5
#define AI_TOOLS_VERSION_MINOR 2
#define AI_TOOLS_VERSION_MICRO 0


#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 3
#define AI_TOOLS_API_VERSION_MICRO 0

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_facerecognition
 
#undef AI_FACERECOGNITION_MODEL_SIGNATURE
#define AI_FACERECOGNITION_MODEL_SIGNATURE     "8eb2c174805b8fda5a3f45ca95f92915"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.2.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Sun Jan  3 04:46:43 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_FACERECOGNITION_N_BATCHES
#define AI_FACERECOGNITION_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array conv2d_2_scratch0_array;   /* Array #0 */
AI_STATIC ai_array conv2d_0_scratch0_array;   /* Array #1 */
AI_STATIC ai_array dense_5_bias_array;   /* Array #2 */
AI_STATIC ai_array dense_5_weights_array;   /* Array #3 */
AI_STATIC ai_array conv2d_2_bias_array;   /* Array #4 */
AI_STATIC ai_array conv2d_2_weights_array;   /* Array #5 */
AI_STATIC ai_array conv2d_0_bias_array;   /* Array #6 */
AI_STATIC ai_array conv2d_0_weights_array;   /* Array #7 */
AI_STATIC ai_array serving_default_x_input0_output_array;   /* Array #8 */
AI_STATIC ai_array conv2d_0_output_array;   /* Array #9 */
AI_STATIC ai_array conv2d_2_output_array;   /* Array #10 */
AI_STATIC ai_array dense_5_output_array;   /* Array #11 */
AI_STATIC ai_array nl_6_output_array;   /* Array #12 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor conv2d_2_scratch0;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_0_scratch0;   /* Tensor #1 */
AI_STATIC ai_tensor dense_5_bias;   /* Tensor #2 */
AI_STATIC ai_tensor dense_5_weights;   /* Tensor #3 */
AI_STATIC ai_tensor conv2d_2_bias;   /* Tensor #4 */
AI_STATIC ai_tensor conv2d_2_weights;   /* Tensor #5 */
AI_STATIC ai_tensor conv2d_0_bias;   /* Tensor #6 */
AI_STATIC ai_tensor conv2d_0_weights;   /* Tensor #7 */
AI_STATIC ai_tensor serving_default_x_input0_output;   /* Tensor #8 */
AI_STATIC ai_tensor conv2d_0_output;   /* Tensor #9 */
AI_STATIC ai_tensor conv2d_2_output;   /* Tensor #10 */
AI_STATIC ai_tensor conv2d_2_output0;   /* Tensor #11 */
AI_STATIC ai_tensor dense_5_output;   /* Tensor #12 */
AI_STATIC ai_tensor nl_6_output;   /* Tensor #13 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv2d_0_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_2_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain dense_5_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain nl_6_chain;   /* Chain #3 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_conv2d_nl_pool conv2d_0_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d_nl_pool conv2d_2_layer; /* Layer #1 */
AI_STATIC ai_layer_dense dense_5_layer; /* Layer #2 */
AI_STATIC ai_layer_nl nl_6_layer; /* Layer #3 */


/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6144, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  dense_5_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  dense_5_weights_array, AI_ARRAY_FORMAT_LUT8_FLOAT,
  NULL, NULL, 18432, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4608, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 864, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_x_input0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 27648, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 73728, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 9216, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  dense_5_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  nl_6_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 2, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 48, 2), AI_STRIDE_INIT(4, 4, 4, 64, 3072),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 96, 2), AI_STRIDE_INIT(4, 4, 4, 128, 12288),
  1, &conv2d_0_scratch0_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  dense_5_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &dense_5_bias_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  dense_5_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 9216, 2, 1, 1), AI_STRIDE_INIT(4, 1, 9216, 18432, 18432),
  1, &dense_5_weights_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_2_bias_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 32, 3, 3, 16), AI_STRIDE_INIT(4, 4, 128, 384, 1152),
  1, &conv2d_2_weights_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_0_bias_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 3, 3, 3, 32), AI_STRIDE_INIT(4, 4, 12, 36, 108),
  1, &conv2d_0_weights_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_x_input0_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 96, 96), AI_STRIDE_INIT(4, 4, 4, 12, 1152),
  1, &serving_default_x_input0_output_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 48, 48), AI_STRIDE_INIT(4, 4, 4, 128, 6144),
  1, &conv2d_0_output_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 24, 24), AI_STRIDE_INIT(4, 4, 4, 64, 1536),
  1, &conv2d_2_output_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 9216, 1, 1), AI_STRIDE_INIT(4, 4, 4, 36864, 36864),
  1, &conv2d_2_output_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  dense_5_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &dense_5_output_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  nl_6_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &nl_6_output_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_x_input0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_0_weights, &conv2d_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_0_layer, 0,
  OPTIMIZED_CONV2D_TYPE,
  conv2d_nl_pool, forward_conv2d_nl_pool,
  &AI_NET_OBJ_INSTANCE, &conv2d_2_layer, AI_STATIC,
  .tensors = &conv2d_0_chain, 
  .groups = 1, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
  .pool_func = pool_func_mp_array_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 2,
  OPTIMIZED_CONV2D_TYPE,
  conv2d_nl_pool, forward_conv2d_nl_pool,
  &AI_NET_OBJ_INSTANCE, &dense_5_layer, AI_STATIC,
  .tensors = &conv2d_2_chain, 
  .groups = 1, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
  .pool_func = pool_func_mp_array_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_5_weights, &dense_5_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_5_layer, 5,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &nl_6_layer, AI_STATIC,
  .tensors = &dense_5_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_6_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_6_layer, 6,
  NL_TYPE,
  nl, forward_sm,
  &AI_NET_OBJ_INSTANCE, &nl_6_layer, AI_STATIC,
  .tensors = &nl_6_chain, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 41544, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 319488, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_FACERECOGNITION_IN_NUM, &serving_default_x_input0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_FACERECOGNITION_OUT_NUM, &nl_6_output),
  &conv2d_0_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool facerecognition_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, AI_FACERECOGNITION_ACTIVATIONS_ALIGNMENT));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    conv2d_2_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_2_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_0_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_0_scratch0_array.data_start = AI_PTR(activations + 0);
    serving_default_x_input0_output_array.data = AI_PTR(NULL);
    serving_default_x_input0_output_array.data_start = AI_PTR(NULL);
    conv2d_0_output_array.data = AI_PTR(activations + 24576);
    conv2d_0_output_array.data_start = AI_PTR(activations + 24576);
    conv2d_2_output_array.data = AI_PTR(activations + 21376);
    conv2d_2_output_array.data_start = AI_PTR(activations + 21376);
    dense_5_output_array.data = AI_PTR(activations + 0);
    dense_5_output_array.data_start = AI_PTR(activations + 0);
    nl_6_output_array.data = AI_PTR(NULL);
    nl_6_output_array.data_start = AI_PTR(NULL);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool facerecognition_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    dense_5_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_5_bias_array.data = AI_PTR(weights + 41536);
    dense_5_bias_array.data_start = AI_PTR(weights + 41536);
    dense_5_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_5_weights_array.data = AI_PTR(weights + 23104);
    dense_5_weights_array.data_start = AI_PTR(weights + 22080);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(weights + 22016);
    conv2d_2_bias_array.data_start = AI_PTR(weights + 22016);
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(weights + 3584);
    conv2d_2_weights_array.data_start = AI_PTR(weights + 3584);
    conv2d_0_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_0_bias_array.data = AI_PTR(weights + 3456);
    conv2d_0_bias_array.data_start = AI_PTR(weights + 3456);
    conv2d_0_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_0_weights_array.data = AI_PTR(weights + 0);
    conv2d_0_weights_array.data_start = AI_PTR(weights + 0);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_facerecognition_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_FACERECOGNITION_MODEL_NAME,
      .model_signature   = AI_FACERECOGNITION_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = {AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR,
                            AI_TOOLS_API_VERSION_MICRO, 0x0},

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 19261518,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if ( !ai_platform_api_get_network_report(network, &r) ) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_facerecognition_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_facerecognition_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_facerecognition_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_facerecognition_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= facerecognition_configure_weights(net_ctx, &params->params);
  ok &= facerecognition_configure_activations(net_ctx, &params->activations);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_facerecognition_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_facerecognition_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}




#undef AI_FACERECOGNITION_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

