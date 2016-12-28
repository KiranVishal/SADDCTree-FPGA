module test;
  reg[31:0] io_fBlock = 0;
  reg[31:0] io_wBlock = 0;
  wire[0:0] io_decision;
  reg clk = 0;
  integer clk_len;
  always #clk_len clk = ~clk;
  reg vcdon = 0;
  reg [1023:0] vcdfile = 0;
  reg [1023:0] vpdfile = 0;

  /*** DUT instantiation ***/
  ControlUnit ControlUnit(
    .io_fBlock(io_fBlock),
    .io_wBlock(io_wBlock),
    .io_decision(io_decision));

  initial begin
    clk_len = `CLOCK_PERIOD;
    $init_clks(clk_len);
    $init_rsts();
    $init_ins(io_fBlock, io_wBlock);
    $init_outs(io_decision);
    $init_sigs(ControlUnit);
    /*** VCD & VPD dump ***/
    if ($value$plusargs("vcdfile=%s", vcdfile)) begin
      $dumpfile(vcdfile);
      $dumpvars(0, ControlUnit);
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
  end

endmodule
