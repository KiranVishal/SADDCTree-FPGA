module Comparator(input clk, input reset,
    output io_req_ready,
    input  io_req_valid,
    input [31:0] io_req_bits_feature,
    input [31:0] io_req_bits_weights,
    input  io_resp_ready,
    output io_resp_valid,
    output io_resp_bits_decision
);

  wire T0;
  wire[15:0] T1;
  wire dataOut;
  wire T2;
  wire T3;


`ifndef SYNTHESIS
// synthesis translate_off
//  assign io_resp_valid = {1{$random}};
//  assign io_req_ready = {1{$random}};
// synthesis translate_on
`endif
  assign T0 = reset ^ 1'h1;
  assign io_resp_bits_decision = dataOut;
  assign dataOut = T2;
  assign T2 = T3 ? 1'h1 : 1'h0;
  assign T3 = $signed(io_req_bits_feature) <= $signed(io_req_bits_weights);

  always @(posedge clk) begin
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T0)
        $fwrite(32'h80000002, "hi");
// synthesis translate_on
`endif
  end
endmodule

