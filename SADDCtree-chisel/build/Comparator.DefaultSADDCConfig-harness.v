module test;
  reg[0:0] io_req_valid = 0;
  reg[31:0] io_req_bits_feature = 0;
  reg[31:0] io_req_bits_weights = 0;
  reg[0:0] io_resp_ready = 0;
  wire[0:0] io_req_ready;
  wire[0:0] io_resp_valid;
  wire[0:0] io_resp_bits_decision;
  reg clk = 0;
  reg reset = 1;
  integer clk_len;
  always #clk_len clk = ~clk;
  reg vcdon = 0;
  reg [1023:0] vcdfile = 0;
  reg [1023:0] vpdfile = 0;

  /*** DUT instantiation ***/
  Comparator Comparator(
    .clk(clk),
    .reset(reset),
    .io_req_valid(io_req_valid),
    .io_req_bits_feature(io_req_bits_feature),
    .io_req_bits_weights(io_req_bits_weights),
    .io_resp_ready(io_resp_ready),
    .io_req_ready(io_req_ready),
    .io_resp_valid(io_resp_valid),
    .io_resp_bits_decision(io_resp_bits_decision));

  initial begin
    clk_len = `CLOCK_PERIOD;
    $init_clks(clk_len);
    $init_rsts(reset);
    $init_ins(io_req_valid, io_req_bits_feature, io_req_bits_weights, io_resp_ready);
    $init_outs(io_req_ready, io_resp_valid, io_resp_bits_decision);
    $init_sigs(Comparator);
    /*** VCD & VPD dump ***/
    if ($value$plusargs("vcdfile=%s", vcdfile)) begin
      $dumpfile(vcdfile);
      $dumpvars(0, Comparator);
      $dumpoff;
      vcdon = 0;
    end
    if ($value$plusargs("vpdfile=%s", vpdfile)) begin
      $vcdplusfile(vpdfile);
      $vcdpluson(0);
      $vcdplusautoflushon;
    end
    if ($test$plusargs("vpdmem")) begin
      $vcdplusmemon;
    end
  end

  always @(negedge clk) begin
    $tick();
    if (vcdfile && (reset)) begin
      $dumpoff;
      vcdon = 0;
    end
    else if (vcdfile && !vcdon) begin
      $dumpon;
      vcdon = 1;
    end
  end

endmodule
