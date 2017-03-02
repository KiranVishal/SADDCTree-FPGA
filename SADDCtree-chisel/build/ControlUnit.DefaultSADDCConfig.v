module Comparator_0(
    //output io_req_ready
    //input  io_req_valid
    input [31:0] io_req_bits_feature,
    input [31:0] io_req_bits_weights,
    input  io_req_bits_index,
    //input  io_resp_ready
    //output io_resp_valid
    output io_resp_bits_decision,
    output io_resp_bits_index
);

  wire dataOut;
  wire T0;
  wire T1;


`ifndef SYNTHESIS
// synthesis translate_off
//  assign io_resp_valid = {1{$random}};
//  assign io_req_ready = {1{$random}};
// synthesis translate_on
`endif
  assign io_resp_bits_index = io_req_bits_index;
  assign io_resp_bits_decision = dataOut;
  assign dataOut = T0;
  assign T0 = T1 ? 1'h1 : 1'h0;
  assign T1 = $signed(io_req_bits_feature) <= $signed(io_req_bits_weights);
endmodule

module Comparator_1(
    //output io_req_ready
    //input  io_req_valid
    input [31:0] io_req_bits_feature,
    input [31:0] io_req_bits_weights,
    input [1:0] io_req_bits_index,
    //input  io_resp_ready
    //output io_resp_valid
    output io_resp_bits_decision,
    output[1:0] io_resp_bits_index
);

  wire dataOut;
  wire T0;
  wire T1;


`ifndef SYNTHESIS
// synthesis translate_off
//  assign io_resp_valid = {1{$random}};
//  assign io_req_ready = {1{$random}};
// synthesis translate_on
`endif
  assign io_resp_bits_index = io_req_bits_index;
  assign io_resp_bits_decision = dataOut;
  assign dataOut = T0;
  assign T0 = T1 ? 1'h1 : 1'h0;
  assign T1 = $signed(io_req_bits_feature) <= $signed(io_req_bits_weights);
endmodule

module Comparator_2(
    //output io_req_ready
    //input  io_req_valid
    input [31:0] io_req_bits_feature,
    input [31:0] io_req_bits_weights,
    input [2:0] io_req_bits_index,
    //input  io_resp_ready
    //output io_resp_valid
    output io_resp_bits_decision,
    output[2:0] io_resp_bits_index
);

  wire dataOut;
  wire T0;
  wire T1;


`ifndef SYNTHESIS
// synthesis translate_off
//  assign io_resp_valid = {1{$random}};
//  assign io_req_ready = {1{$random}};
// synthesis translate_on
`endif
  assign io_resp_bits_index = io_req_bits_index;
  assign io_resp_bits_decision = dataOut;
  assign dataOut = T0;
  assign T0 = T1 ? 1'h1 : 1'h0;
  assign T1 = $signed(io_req_bits_feature) <= $signed(io_req_bits_weights);
endmodule

module Comparator_3(
    //output io_req_ready
    //input  io_req_valid
    input [31:0] io_req_bits_feature,
    input [31:0] io_req_bits_weights,
    input [3:0] io_req_bits_index,
    //input  io_resp_ready
    //output io_resp_valid
    output io_resp_bits_decision,
    output[3:0] io_resp_bits_index
);

  wire dataOut;
  wire T0;
  wire T1;


`ifndef SYNTHESIS
// synthesis translate_off
//  assign io_resp_valid = {1{$random}};
//  assign io_req_ready = {1{$random}};
// synthesis translate_on
`endif
  assign io_resp_bits_index = io_req_bits_index;
  assign io_resp_bits_decision = dataOut;
  assign dataOut = T0;
  assign T0 = T1 ? 1'h1 : 1'h0;
  assign T1 = $signed(io_req_bits_feature) <= $signed(io_req_bits_weights);
endmodule

module ControlUnit(
    input [31:0] io_fBlock,
    input [31:0] io_wBlock,
    output io_decision,
    input [31:0] io_n_node,
    input [31:0] io_leaf_node,
    input [31:0] io_nonleaf_node,
    input [31:0] io_current_node,
    input [31:0] io_left_node,
    input [31:0] io_right_node,
    input [31:0] io_feature_index,
    input [31:0] io_optN_comp
);

  wire Comparator_5_io_resp_bits_decision;


  assign io_decision = Comparator_5_io_resp_bits_decision;
  Comparator_0 Comparator(
       //.io_req_ready(  )
       //.io_req_valid(  )
       .io_req_bits_feature( io_fBlock ),
       .io_req_bits_weights( io_wBlock ),
       .io_req_bits_index( 1'h0 )
       //.io_resp_ready(  )
       //.io_resp_valid(  )
       //.io_resp_bits_decision(  )
       //.io_resp_bits_index(  )
  );
  Comparator_0 Comparator_1(
       //.io_req_ready(  )
       //.io_req_valid(  )
       .io_req_bits_feature( io_fBlock ),
       .io_req_bits_weights( io_wBlock ),
       .io_req_bits_index( 1'h1 )
       //.io_resp_ready(  )
       //.io_resp_valid(  )
       //.io_resp_bits_decision(  )
       //.io_resp_bits_index(  )
  );
  Comparator_1 Comparator_2(
       //.io_req_ready(  )
       //.io_req_valid(  )
       .io_req_bits_feature( io_fBlock ),
       .io_req_bits_weights( io_wBlock ),
       .io_req_bits_index( 2'h2 )
       //.io_resp_ready(  )
       //.io_resp_valid(  )
       //.io_resp_bits_decision(  )
       //.io_resp_bits_index(  )
  );
  Comparator_1 Comparator_3(
       //.io_req_ready(  )
       //.io_req_valid(  )
       .io_req_bits_feature( io_fBlock ),
       .io_req_bits_weights( io_wBlock ),
       .io_req_bits_index( 2'h3 )
       //.io_resp_ready(  )
       //.io_resp_valid(  )
       //.io_resp_bits_decision(  )
       //.io_resp_bits_index(  )
  );
  Comparator_2 Comparator_4(
       //.io_req_ready(  )
       //.io_req_valid(  )
       .io_req_bits_feature( io_fBlock ),
       .io_req_bits_weights( io_wBlock ),
       .io_req_bits_index( 3'h4 )
       //.io_resp_ready(  )
       //.io_resp_valid(  )
       //.io_resp_bits_decision(  )
       //.io_resp_bits_index(  )
  );
  Comparator_2 Comparator_5(
       //.io_req_ready(  )
       //.io_req_valid(  )
       .io_req_bits_feature( io_fBlock ),
       .io_req_bits_weights( io_wBlock ),
       .io_req_bits_index( 3'h5 ),
       //.io_resp_ready(  )
       //.io_resp_valid(  )
       .io_resp_bits_decision( Comparator_5_io_resp_bits_decision )
       //.io_resp_bits_index(  )
  );
  Comparator_2 Comparator_6(
       //.io_req_ready(  )
       //.io_req_valid(  )
       .io_req_bits_feature( io_fBlock ),
       .io_req_bits_weights( io_wBlock ),
       .io_req_bits_index( 3'h6 )
       //.io_resp_ready(  )
       //.io_resp_valid(  )
       //.io_resp_bits_decision(  )
       //.io_resp_bits_index(  )
  );
  Comparator_2 Comparator_7(
       //.io_req_ready(  )
       //.io_req_valid(  )
       .io_req_bits_feature( io_fBlock ),
       .io_req_bits_weights( io_wBlock ),
       .io_req_bits_index( 3'h7 )
       //.io_resp_ready(  )
       //.io_resp_valid(  )
       //.io_resp_bits_decision(  )
       //.io_resp_bits_index(  )
  );
  Comparator_3 Comparator_8(
       //.io_req_ready(  )
       //.io_req_valid(  )
       .io_req_bits_feature( io_fBlock ),
       .io_req_bits_weights( io_wBlock ),
       .io_req_bits_index( 4'h8 )
       //.io_resp_ready(  )
       //.io_resp_valid(  )
       //.io_resp_bits_decision(  )
       //.io_resp_bits_index(  )
  );
  Comparator_3 Comparator_9(
       //.io_req_ready(  )
       //.io_req_valid(  )
       .io_req_bits_feature( io_fBlock ),
       .io_req_bits_weights( io_wBlock ),
       .io_req_bits_index( 4'h9 )
       //.io_resp_ready(  )
       //.io_resp_valid(  )
       //.io_resp_bits_decision(  )
       //.io_resp_bits_index(  )
  );
endmodule

