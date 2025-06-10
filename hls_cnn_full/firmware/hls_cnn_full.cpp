#include <iostream>

#include "hls_cnn_full.h"
#include "parameters.h"


void hls_cnn_full(
    input_t x_in[N_INPUT_1_1*N_INPUT_2_1*N_INPUT_3_1],
    result_t layer19_out[N_LAYER_17]
) {

    // hls-fpga-machine-learning insert IO
    #pragma HLS ARRAY_RESHAPE variable=x_in complete dim=0
    #pragma HLS ARRAY_PARTITION variable=layer19_out complete dim=0
    #pragma HLS INTERFACE ap_vld port=x_in,layer19_out 
    #pragma HLS DATAFLOW

    // hls-fpga-machine-learning insert load weights
#ifndef __SYNTHESIS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        nnet::load_weights_from_txt<weight2_t, 27>(w2, "w2.txt");
        nnet::load_weights_from_txt<bias2_t, 3>(b2, "b2.txt");
        nnet::load_weights_from_txt<weight6_t, 81>(w6, "w6.txt");
        nnet::load_weights_from_txt<bias6_t, 3>(b6, "b6.txt");
        nnet::load_weights_from_txt<weight10_t, 81>(w10, "w10.txt");
        nnet::load_weights_from_txt<bias10_t, 3>(b10, "b10.txt");
        nnet::load_weights_from_txt<weight14_t, 9600>(w14, "w14.txt");
        nnet::load_weights_from_txt<bias14_t, 32>(b14, "b14.txt");
        nnet::load_weights_from_txt<weight17_t, 320>(w17, "w17.txt");
        nnet::load_weights_from_txt<bias17_t, 10>(b17, "b17.txt");
        loaded_weights = true;    }
#endif
    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    // hls-fpga-machine-learning insert layers

    conv1_result_t layer2_out[OUT_HEIGHT_2*OUT_WIDTH_2*N_FILT_2];
    #pragma HLS ARRAY_PARTITION variable=layer2_out complete dim=0
    nnet::conv_2d_cl<input_t, conv1_result_t, config2>(x_in, layer2_out, w2, b2); // conv1

    layer4_t layer4_out[OUT_HEIGHT_2*OUT_WIDTH_2*N_FILT_2];
    #pragma HLS ARRAY_PARTITION variable=layer4_out complete dim=0
    nnet::relu<conv1_result_t, layer4_t, relu_config4>(layer2_out, layer4_out); // relu1

    layer5_t layer5_out[OUT_HEIGHT_5*OUT_WIDTH_5*N_FILT_5];
    #pragma HLS ARRAY_PARTITION variable=layer5_out complete dim=0
    nnet::pooling2d_cl<layer4_t, layer5_t, config5>(layer4_out, layer5_out); // pool1

    conv2_result_t layer6_out[OUT_HEIGHT_6*OUT_WIDTH_6*N_FILT_6];
    #pragma HLS ARRAY_PARTITION variable=layer6_out complete dim=0
    nnet::conv_2d_cl<layer5_t, conv2_result_t, config6>(layer5_out, layer6_out, w6, b6); // conv2

    layer8_t layer8_out[OUT_HEIGHT_6*OUT_WIDTH_6*N_FILT_6];
    #pragma HLS ARRAY_PARTITION variable=layer8_out complete dim=0
    nnet::relu<conv2_result_t, layer8_t, relu_config8>(layer6_out, layer8_out); // relu2

    layer9_t layer9_out[OUT_HEIGHT_9*OUT_WIDTH_9*N_FILT_9];
    #pragma HLS ARRAY_PARTITION variable=layer9_out complete dim=0
    nnet::pooling2d_cl<layer8_t, layer9_t, config9>(layer8_out, layer9_out); // pool2

    conv3_result_t layer10_out[OUT_HEIGHT_10*OUT_WIDTH_10*N_FILT_10];
    #pragma HLS ARRAY_PARTITION variable=layer10_out complete dim=0
    nnet::conv_2d_cl<layer9_t, conv3_result_t, config10>(layer9_out, layer10_out, w10, b10); // conv3

    layer12_t layer12_out[OUT_HEIGHT_10*OUT_WIDTH_10*N_FILT_10];
    #pragma HLS ARRAY_PARTITION variable=layer12_out complete dim=0
    nnet::relu<conv3_result_t, layer12_t, relu_config12>(layer10_out, layer12_out); // relu3

    auto& layer13_out = layer12_out;
    dense1_result_t layer14_out[N_LAYER_14];
    #pragma HLS ARRAY_PARTITION variable=layer14_out complete dim=0
    nnet::dense<layer12_t, dense1_result_t, config14>(layer13_out, layer14_out, w14, b14); // dense1

    layer16_t layer16_out[N_LAYER_14];
    #pragma HLS ARRAY_PARTITION variable=layer16_out complete dim=0
    nnet::relu<dense1_result_t, layer16_t, relu_config16>(layer14_out, layer16_out); // relu4

    dense2_result_t layer17_out[N_LAYER_17];
    #pragma HLS ARRAY_PARTITION variable=layer17_out complete dim=0
    nnet::dense<layer16_t, dense2_result_t, config17>(layer16_out, layer17_out, w17, b17); // dense2

    nnet::softmax<dense2_result_t, result_t, softmax_config19>(layer17_out, layer19_out); // softmax

}

