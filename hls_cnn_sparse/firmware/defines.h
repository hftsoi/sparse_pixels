#ifndef DEFINES_H_
#define DEFINES_H_

#include "ap_fixed.h"
#include "ap_int.h"
#include "nnet_utils/nnet_types.h"
#include <cstddef>
#include <cstdio>

// hls-fpga-machine-learning insert numbers
#define N_INPUT_1_1 40
#define N_INPUT_2_1 40
#define N_INPUT_3_1 1
#define OUT_HEIGHT_2 40
#define OUT_WIDTH_2 40
#define N_FILT_2 3
#define OUT_HEIGHT_2 40
#define OUT_WIDTH_2 40
#define N_FILT_2 3
#define OUT_HEIGHT_5 20
#define OUT_WIDTH_5 20
#define N_FILT_5 3
#define OUT_HEIGHT_6 20
#define OUT_WIDTH_6 20
#define N_FILT_6 3
#define OUT_HEIGHT_6 20
#define OUT_WIDTH_6 20
#define N_FILT_6 3
#define OUT_HEIGHT_9 10
#define OUT_WIDTH_9 10
#define N_FILT_9 3
#define OUT_HEIGHT_10 10
#define OUT_WIDTH_10 10
#define N_FILT_10 3
#define OUT_HEIGHT_10 10
#define OUT_WIDTH_10 10
#define N_FILT_10 3
#define N_SIZE_0_13 300
#define N_LAYER_14 32
#define N_LAYER_14 32
#define N_LAYER_17 10
#define N_LAYER_17 10


// hls-fpga-machine-learning insert layer-precision
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<27,12> conv1_accum_t;
typedef ap_fixed<27,12> conv1_result_t;
typedef ap_fixed<6,1> weight2_t;
typedef ap_fixed<6,1> bias2_t;
typedef ap_ufixed<6,0,AP_RND_CONV,AP_SAT,0> layer4_t;
typedef ap_fixed<18,8> relu1_table_t;
typedef ap_ufixed<10,2> pool1_accum_t;
typedef ap_ufixed<6,0,AP_RND_CONV,AP_SAT,0> layer5_t;
typedef ap_fixed<18,7> conv2_accum_t;
typedef ap_fixed<18,7> conv2_result_t;
typedef ap_fixed<6,1> weight6_t;
typedef ap_fixed<6,1> bias6_t;
typedef ap_ufixed<6,0,AP_RND_CONV,AP_SAT,0> layer8_t;
typedef ap_fixed<18,8> relu2_table_t;
typedef ap_ufixed<10,2> pool2_accum_t;
typedef ap_ufixed<6,0,AP_RND_CONV,AP_SAT,0> layer9_t;
typedef ap_fixed<18,7> conv3_accum_t;
typedef ap_fixed<18,7> conv3_result_t;
typedef ap_fixed<6,1> weight10_t;
typedef ap_fixed<6,1> bias10_t;
typedef ap_ufixed<6,0,AP_RND_CONV,AP_SAT,0> layer12_t;
typedef ap_fixed<18,8> relu3_table_t;
typedef ap_fixed<22,11> dense1_accum_t;
typedef ap_fixed<22,11> dense1_result_t;
typedef ap_fixed<6,1> weight14_t;
typedef ap_fixed<6,1> bias14_t;
typedef ap_uint<1> layer14_index;
typedef ap_ufixed<6,0,AP_RND_CONV,AP_SAT,0> layer16_t;
typedef ap_fixed<18,8> relu4_table_t;
typedef ap_fixed<18,7> dense2_accum_t;
typedef ap_fixed<18,7> dense2_result_t;
typedef ap_fixed<6,1> weight17_t;
typedef ap_fixed<6,1> bias17_t;
typedef ap_uint<1> layer17_index;
typedef ap_fixed<16,6> result_t;
typedef ap_fixed<18,8> softmax_table_t;
typedef ap_fixed<18,8,AP_RND,AP_SAT,0> softmax_exp_table_t;
typedef ap_fixed<18,8,AP_RND,AP_SAT,0> softmax_inv_table_t;


#endif
