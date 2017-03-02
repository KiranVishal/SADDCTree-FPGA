module test;
  reg[31:0] io_fBlock = 0;
  reg[31:0] io_wBlock = 0;
  reg[31:0] io_n_node = 0;
  reg[31:0] io_leaf_node = 0;
  reg[31:0] io_nonleaf_node = 0;
  reg[31:0] io_current_node = 0;
  reg[31:0] io_left_node = 0;
  reg[31:0] io_right_node = 0;
  reg[31:0] io_feature_index = 0;
  reg[31:0] io_optN_comp = 0;
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
    .io_n_node(io_n_node),
    .io_leaf_node(io_leaf_node),
    .io_nonleaf_node(io_nonleaf_node),
    .io_current_node(io_current_node),
    .io_left_node(io_left_node),
    .io_right_node(io_right_node),
    .io_feature_index(io_feature_index),
    .io_optN_comp(io_optN_comp),
    .io_decision(io_decision));

  initial begin
    clk_len = `CLOCK_PERIOD;
    $init_clks(clk_len);
    $init_rsts();
    $init_ins(io_fBlock, io_wBlock, io_n_node, io_leaf_node, io_nonleaf_node, io_current_node, io_left_node, io_right_node, io_feature_index, io_optN_comp);
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
