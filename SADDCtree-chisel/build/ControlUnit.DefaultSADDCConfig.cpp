#include "ControlUnit.DefaultSADDCConfig.h"

void ControlUnit_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  clk.len = 1;
  clk.cnt = 0;
  clk.values[0] = 0;
}


int ControlUnit_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk.cnt < min) min = clk.cnt;
  clk.cnt-=min;
  if (clk.cnt == 0) clock_lo( reset );
  if (!reset.to_bool()) print( std::cerr );
  if (clk.cnt == 0) clock_hi( reset );
  if (clk.cnt == 0) clk.cnt = clk.len;
  return min;
}


void ControlUnit_t::print ( FILE* f ) {
}
void ControlUnit_t::print ( std::ostream& s ) {
}


void ControlUnit_t::dump_init ( FILE* f ) {
}


void ControlUnit_t::dump ( FILE* f, val_t t, dat_t<1> reset ) {
}




void ControlUnit_t::clock_lo ( dat_t<1> reset, bool assert_fire ) {
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_9__io_req_ready.values[0] = __r;}
  ControlUnit_Comparator_9__io_req_ready.values[0] = ControlUnit_Comparator_9__io_req_ready.values[0] & 0x1L;
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_9__io_resp_valid.values[0] = __r;}
  ControlUnit_Comparator_9__io_resp_valid.values[0] = ControlUnit_Comparator_9__io_resp_valid.values[0] & 0x1L;
  { ControlUnit_Comparator_9__io_req_bits_feature.values[0] = ControlUnit__io_fBlock.values[0];}
  val_t T0;
  T0 = (ControlUnit_Comparator_9__io_req_bits_feature.values[0] >> 31) & 1;
  { ControlUnit_Comparator_9__io_req_bits_weights.values[0] = ControlUnit__io_wBlock.values[0];}
  val_t T1;
  T1 = ControlUnit_Comparator_9__io_req_bits_feature.values[0]<=ControlUnit_Comparator_9__io_req_bits_weights.values[0];
  val_t T2;
  T2 = (ControlUnit_Comparator_9__io_req_bits_weights.values[0] >> 31) & 1;
  val_t T3;
  T3 = T0 == T2;
  val_t T4;
  { T4 = TERNARY_1(T3, T1, T0);}
  val_t T5;
  { T5 = TERNARY(T4, 0x1L, 0x0L);}
  { ControlUnit_Comparator_9__io_resp_bits_decision.values[0] = T5;}
  { ControlUnit_Comparator_9__io_req_bits_index.values[0] = 0x9L;}
  { ControlUnit_Comparator_9__io_resp_bits_index.values[0] = ControlUnit_Comparator_9__io_req_bits_index.values[0];}
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_8__io_req_ready.values[0] = __r;}
  ControlUnit_Comparator_8__io_req_ready.values[0] = ControlUnit_Comparator_8__io_req_ready.values[0] & 0x1L;
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_8__io_resp_valid.values[0] = __r;}
  ControlUnit_Comparator_8__io_resp_valid.values[0] = ControlUnit_Comparator_8__io_resp_valid.values[0] & 0x1L;
  { ControlUnit_Comparator_8__io_req_bits_feature.values[0] = ControlUnit__io_fBlock.values[0];}
  val_t T6;
  T6 = (ControlUnit_Comparator_8__io_req_bits_feature.values[0] >> 31) & 1;
  { ControlUnit_Comparator_8__io_req_bits_weights.values[0] = ControlUnit__io_wBlock.values[0];}
  val_t T7;
  T7 = ControlUnit_Comparator_8__io_req_bits_feature.values[0]<=ControlUnit_Comparator_8__io_req_bits_weights.values[0];
  val_t T8;
  T8 = (ControlUnit_Comparator_8__io_req_bits_weights.values[0] >> 31) & 1;
  val_t T9;
  T9 = T6 == T8;
  val_t T10;
  { T10 = TERNARY_1(T9, T7, T6);}
  val_t T11;
  { T11 = TERNARY(T10, 0x1L, 0x0L);}
  { ControlUnit_Comparator_8__io_resp_bits_decision.values[0] = T11;}
  { ControlUnit_Comparator_8__io_req_bits_index.values[0] = 0x8L;}
  { ControlUnit_Comparator_8__io_resp_bits_index.values[0] = ControlUnit_Comparator_8__io_req_bits_index.values[0];}
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_7__io_req_ready.values[0] = __r;}
  ControlUnit_Comparator_7__io_req_ready.values[0] = ControlUnit_Comparator_7__io_req_ready.values[0] & 0x1L;
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_7__io_resp_valid.values[0] = __r;}
  ControlUnit_Comparator_7__io_resp_valid.values[0] = ControlUnit_Comparator_7__io_resp_valid.values[0] & 0x1L;
  { ControlUnit_Comparator_7__io_req_bits_feature.values[0] = ControlUnit__io_fBlock.values[0];}
  val_t T12;
  T12 = (ControlUnit_Comparator_7__io_req_bits_feature.values[0] >> 31) & 1;
  { ControlUnit_Comparator_7__io_req_bits_weights.values[0] = ControlUnit__io_wBlock.values[0];}
  val_t T13;
  T13 = ControlUnit_Comparator_7__io_req_bits_feature.values[0]<=ControlUnit_Comparator_7__io_req_bits_weights.values[0];
  val_t T14;
  T14 = (ControlUnit_Comparator_7__io_req_bits_weights.values[0] >> 31) & 1;
  val_t T15;
  T15 = T12 == T14;
  val_t T16;
  { T16 = TERNARY_1(T15, T13, T12);}
  val_t T17;
  { T17 = TERNARY(T16, 0x1L, 0x0L);}
  { ControlUnit_Comparator_7__io_resp_bits_decision.values[0] = T17;}
  { ControlUnit_Comparator_7__io_req_bits_index.values[0] = 0x7L;}
  { ControlUnit_Comparator_7__io_resp_bits_index.values[0] = ControlUnit_Comparator_7__io_req_bits_index.values[0];}
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_6__io_req_ready.values[0] = __r;}
  ControlUnit_Comparator_6__io_req_ready.values[0] = ControlUnit_Comparator_6__io_req_ready.values[0] & 0x1L;
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_6__io_resp_valid.values[0] = __r;}
  ControlUnit_Comparator_6__io_resp_valid.values[0] = ControlUnit_Comparator_6__io_resp_valid.values[0] & 0x1L;
  { ControlUnit_Comparator_6__io_req_bits_feature.values[0] = ControlUnit__io_fBlock.values[0];}
  val_t T18;
  T18 = (ControlUnit_Comparator_6__io_req_bits_feature.values[0] >> 31) & 1;
  { ControlUnit_Comparator_6__io_req_bits_weights.values[0] = ControlUnit__io_wBlock.values[0];}
  val_t T19;
  T19 = ControlUnit_Comparator_6__io_req_bits_feature.values[0]<=ControlUnit_Comparator_6__io_req_bits_weights.values[0];
  val_t T20;
  T20 = (ControlUnit_Comparator_6__io_req_bits_weights.values[0] >> 31) & 1;
  val_t T21;
  T21 = T18 == T20;
  val_t T22;
  { T22 = TERNARY_1(T21, T19, T18);}
  val_t T23;
  { T23 = TERNARY(T22, 0x1L, 0x0L);}
  { ControlUnit_Comparator_6__io_resp_bits_decision.values[0] = T23;}
  { ControlUnit_Comparator_6__io_req_bits_index.values[0] = 0x6L;}
  { ControlUnit_Comparator_6__io_resp_bits_index.values[0] = ControlUnit_Comparator_6__io_req_bits_index.values[0];}
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_5__io_req_ready.values[0] = __r;}
  ControlUnit_Comparator_5__io_req_ready.values[0] = ControlUnit_Comparator_5__io_req_ready.values[0] & 0x1L;
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_5__io_resp_valid.values[0] = __r;}
  ControlUnit_Comparator_5__io_resp_valid.values[0] = ControlUnit_Comparator_5__io_resp_valid.values[0] & 0x1L;
  { ControlUnit_Comparator_5__io_req_bits_index.values[0] = 0x5L;}
  { ControlUnit_Comparator_5__io_resp_bits_index.values[0] = ControlUnit_Comparator_5__io_req_bits_index.values[0];}
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_4__io_req_ready.values[0] = __r;}
  ControlUnit_Comparator_4__io_req_ready.values[0] = ControlUnit_Comparator_4__io_req_ready.values[0] & 0x1L;
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_4__io_resp_valid.values[0] = __r;}
  ControlUnit_Comparator_4__io_resp_valid.values[0] = ControlUnit_Comparator_4__io_resp_valid.values[0] & 0x1L;
  { ControlUnit_Comparator_4__io_req_bits_feature.values[0] = ControlUnit__io_fBlock.values[0];}
  val_t T24;
  T24 = (ControlUnit_Comparator_4__io_req_bits_feature.values[0] >> 31) & 1;
  { ControlUnit_Comparator_4__io_req_bits_weights.values[0] = ControlUnit__io_wBlock.values[0];}
  val_t T25;
  T25 = ControlUnit_Comparator_4__io_req_bits_feature.values[0]<=ControlUnit_Comparator_4__io_req_bits_weights.values[0];
  val_t T26;
  T26 = (ControlUnit_Comparator_4__io_req_bits_weights.values[0] >> 31) & 1;
  val_t T27;
  T27 = T24 == T26;
  val_t T28;
  { T28 = TERNARY_1(T27, T25, T24);}
  val_t T29;
  { T29 = TERNARY(T28, 0x1L, 0x0L);}
  { ControlUnit_Comparator_4__io_resp_bits_decision.values[0] = T29;}
  { ControlUnit_Comparator_4__io_req_bits_index.values[0] = 0x4L;}
  { ControlUnit_Comparator_4__io_resp_bits_index.values[0] = ControlUnit_Comparator_4__io_req_bits_index.values[0];}
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_3__io_req_ready.values[0] = __r;}
  ControlUnit_Comparator_3__io_req_ready.values[0] = ControlUnit_Comparator_3__io_req_ready.values[0] & 0x1L;
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_3__io_resp_valid.values[0] = __r;}
  ControlUnit_Comparator_3__io_resp_valid.values[0] = ControlUnit_Comparator_3__io_resp_valid.values[0] & 0x1L;
  { ControlUnit_Comparator_3__io_req_bits_feature.values[0] = ControlUnit__io_fBlock.values[0];}
  val_t T30;
  T30 = (ControlUnit_Comparator_3__io_req_bits_feature.values[0] >> 31) & 1;
  { ControlUnit_Comparator_3__io_req_bits_weights.values[0] = ControlUnit__io_wBlock.values[0];}
  val_t T31;
  T31 = ControlUnit_Comparator_3__io_req_bits_feature.values[0]<=ControlUnit_Comparator_3__io_req_bits_weights.values[0];
  val_t T32;
  T32 = (ControlUnit_Comparator_3__io_req_bits_weights.values[0] >> 31) & 1;
  val_t T33;
  T33 = T30 == T32;
  val_t T34;
  { T34 = TERNARY_1(T33, T31, T30);}
  val_t T35;
  { T35 = TERNARY(T34, 0x1L, 0x0L);}
  { ControlUnit_Comparator_3__io_resp_bits_decision.values[0] = T35;}
  { ControlUnit_Comparator_3__io_req_bits_index.values[0] = 0x3L;}
  { ControlUnit_Comparator_3__io_resp_bits_index.values[0] = ControlUnit_Comparator_3__io_req_bits_index.values[0];}
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_2__io_req_ready.values[0] = __r;}
  ControlUnit_Comparator_2__io_req_ready.values[0] = ControlUnit_Comparator_2__io_req_ready.values[0] & 0x1L;
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_2__io_resp_valid.values[0] = __r;}
  ControlUnit_Comparator_2__io_resp_valid.values[0] = ControlUnit_Comparator_2__io_resp_valid.values[0] & 0x1L;
  { ControlUnit_Comparator_2__io_req_bits_feature.values[0] = ControlUnit__io_fBlock.values[0];}
  val_t T36;
  T36 = (ControlUnit_Comparator_2__io_req_bits_feature.values[0] >> 31) & 1;
  { ControlUnit_Comparator_2__io_req_bits_weights.values[0] = ControlUnit__io_wBlock.values[0];}
  val_t T37;
  T37 = ControlUnit_Comparator_2__io_req_bits_feature.values[0]<=ControlUnit_Comparator_2__io_req_bits_weights.values[0];
  val_t T38;
  T38 = (ControlUnit_Comparator_2__io_req_bits_weights.values[0] >> 31) & 1;
  val_t T39;
  T39 = T36 == T38;
  val_t T40;
  { T40 = TERNARY_1(T39, T37, T36);}
  val_t T41;
  { T41 = TERNARY(T40, 0x1L, 0x0L);}
  { ControlUnit_Comparator_2__io_resp_bits_decision.values[0] = T41;}
  { ControlUnit_Comparator_2__io_req_bits_index.values[0] = 0x2L;}
  { ControlUnit_Comparator_2__io_resp_bits_index.values[0] = ControlUnit_Comparator_2__io_req_bits_index.values[0];}
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_1__io_req_ready.values[0] = __r;}
  ControlUnit_Comparator_1__io_req_ready.values[0] = ControlUnit_Comparator_1__io_req_ready.values[0] & 0x1L;
  { val_t __r = this->__rand_val(); ControlUnit_Comparator_1__io_resp_valid.values[0] = __r;}
  ControlUnit_Comparator_1__io_resp_valid.values[0] = ControlUnit_Comparator_1__io_resp_valid.values[0] & 0x1L;
  { ControlUnit_Comparator_1__io_req_bits_feature.values[0] = ControlUnit__io_fBlock.values[0];}
  val_t T42;
  T42 = (ControlUnit_Comparator_1__io_req_bits_feature.values[0] >> 31) & 1;
  { ControlUnit_Comparator_1__io_req_bits_weights.values[0] = ControlUnit__io_wBlock.values[0];}
  val_t T43;
  T43 = ControlUnit_Comparator_1__io_req_bits_feature.values[0]<=ControlUnit_Comparator_1__io_req_bits_weights.values[0];
  val_t T44;
  T44 = (ControlUnit_Comparator_1__io_req_bits_weights.values[0] >> 31) & 1;
  val_t T45;
  T45 = T42 == T44;
  val_t T46;
  { T46 = TERNARY_1(T45, T43, T42);}
  val_t T47;
  { T47 = TERNARY(T46, 0x1L, 0x0L);}
  { ControlUnit_Comparator_1__io_resp_bits_decision.values[0] = T47;}
  { ControlUnit_Comparator_1__io_req_bits_index.values[0] = 0x1L;}
  { ControlUnit_Comparator_1__io_resp_bits_index.values[0] = ControlUnit_Comparator_1__io_req_bits_index.values[0];}
  { val_t __r = this->__rand_val(); ControlUnit_Comparator__io_req_ready.values[0] = __r;}
  ControlUnit_Comparator__io_req_ready.values[0] = ControlUnit_Comparator__io_req_ready.values[0] & 0x1L;
  { val_t __r = this->__rand_val(); ControlUnit_Comparator__io_resp_valid.values[0] = __r;}
  ControlUnit_Comparator__io_resp_valid.values[0] = ControlUnit_Comparator__io_resp_valid.values[0] & 0x1L;
  { ControlUnit_Comparator__io_req_bits_feature.values[0] = ControlUnit__io_fBlock.values[0];}
  val_t T48;
  T48 = (ControlUnit_Comparator__io_req_bits_feature.values[0] >> 31) & 1;
  { ControlUnit_Comparator__io_req_bits_weights.values[0] = ControlUnit__io_wBlock.values[0];}
  val_t T49;
  T49 = ControlUnit_Comparator__io_req_bits_feature.values[0]<=ControlUnit_Comparator__io_req_bits_weights.values[0];
  val_t T50;
  T50 = (ControlUnit_Comparator__io_req_bits_weights.values[0] >> 31) & 1;
  val_t T51;
  T51 = T48 == T50;
  val_t T52;
  { T52 = TERNARY_1(T51, T49, T48);}
  val_t T53;
  { T53 = TERNARY(T52, 0x1L, 0x0L);}
  { ControlUnit_Comparator__io_resp_bits_decision.values[0] = T53;}
  { ControlUnit_Comparator__io_req_bits_index.values[0] = 0x0L;}
  { ControlUnit_Comparator__io_resp_bits_index.values[0] = ControlUnit_Comparator__io_req_bits_index.values[0];}
  { ControlUnit_Comparator_5__io_req_bits_feature.values[0] = ControlUnit__io_fBlock.values[0];}
  val_t T54;
  T54 = (ControlUnit_Comparator_5__io_req_bits_feature.values[0] >> 31) & 1;
  { ControlUnit_Comparator_5__io_req_bits_weights.values[0] = ControlUnit__io_wBlock.values[0];}
  val_t T55;
  T55 = ControlUnit_Comparator_5__io_req_bits_feature.values[0]<=ControlUnit_Comparator_5__io_req_bits_weights.values[0];
  val_t T56;
  T56 = (ControlUnit_Comparator_5__io_req_bits_weights.values[0] >> 31) & 1;
  val_t T57;
  T57 = T54 == T56;
  val_t T58;
  { T58 = TERNARY_1(T57, T55, T54);}
  val_t T59;
  { T59 = TERNARY(T58, 0x1L, 0x0L);}
  { ControlUnit_Comparator_5__io_resp_bits_decision.values[0] = T59;}
  { ControlUnit__io_decision.values[0] = ControlUnit_Comparator_5__io_resp_bits_decision.values[0];}
}


void ControlUnit_t::clock_hi ( dat_t<1> reset ) {
}


void ControlUnit_api_t::init_sim_data (  ) {
  sim_data.inputs.clear();
  sim_data.outputs.clear();
  sim_data.signals.clear();
  ControlUnit_t* mod = dynamic_cast<ControlUnit_t*>(module);
  assert(mod);
  sim_data.inputs.push_back(new dat_api<32>(&mod->ControlUnit__io_fBlock));
  sim_data.inputs.push_back(new dat_api<32>(&mod->ControlUnit__io_wBlock));
  sim_data.outputs.push_back(new dat_api<1>(&mod->ControlUnit__io_decision));
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_9__io_req_bits_feature));
  sim_data.signal_map["ControlUnit.Comparator_9.io_req_bits_feature"] = 0;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_9__io_req_bits_weights));
  sim_data.signal_map["ControlUnit.Comparator_9.io_req_bits_weights"] = 1;
  sim_data.signals.push_back(new dat_api<1>(&mod->ControlUnit_Comparator_9__io_resp_bits_decision));
  sim_data.signal_map["ControlUnit.Comparator_9.io_resp_bits_decision"] = 2;
  sim_data.signals.push_back(new dat_api<4>(&mod->ControlUnit_Comparator_9__io_req_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_9.io_req_bits_index"] = 3;
  sim_data.signals.push_back(new dat_api<4>(&mod->ControlUnit_Comparator_9__io_resp_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_9.io_resp_bits_index"] = 4;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_8__io_req_bits_feature));
  sim_data.signal_map["ControlUnit.Comparator_8.io_req_bits_feature"] = 5;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_8__io_req_bits_weights));
  sim_data.signal_map["ControlUnit.Comparator_8.io_req_bits_weights"] = 6;
  sim_data.signals.push_back(new dat_api<1>(&mod->ControlUnit_Comparator_8__io_resp_bits_decision));
  sim_data.signal_map["ControlUnit.Comparator_8.io_resp_bits_decision"] = 7;
  sim_data.signals.push_back(new dat_api<4>(&mod->ControlUnit_Comparator_8__io_req_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_8.io_req_bits_index"] = 8;
  sim_data.signals.push_back(new dat_api<4>(&mod->ControlUnit_Comparator_8__io_resp_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_8.io_resp_bits_index"] = 9;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_7__io_req_bits_feature));
  sim_data.signal_map["ControlUnit.Comparator_7.io_req_bits_feature"] = 10;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_7__io_req_bits_weights));
  sim_data.signal_map["ControlUnit.Comparator_7.io_req_bits_weights"] = 11;
  sim_data.signals.push_back(new dat_api<1>(&mod->ControlUnit_Comparator_7__io_resp_bits_decision));
  sim_data.signal_map["ControlUnit.Comparator_7.io_resp_bits_decision"] = 12;
  sim_data.signals.push_back(new dat_api<3>(&mod->ControlUnit_Comparator_7__io_req_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_7.io_req_bits_index"] = 13;
  sim_data.signals.push_back(new dat_api<3>(&mod->ControlUnit_Comparator_7__io_resp_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_7.io_resp_bits_index"] = 14;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_6__io_req_bits_feature));
  sim_data.signal_map["ControlUnit.Comparator_6.io_req_bits_feature"] = 15;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_6__io_req_bits_weights));
  sim_data.signal_map["ControlUnit.Comparator_6.io_req_bits_weights"] = 16;
  sim_data.signals.push_back(new dat_api<1>(&mod->ControlUnit_Comparator_6__io_resp_bits_decision));
  sim_data.signal_map["ControlUnit.Comparator_6.io_resp_bits_decision"] = 17;
  sim_data.signals.push_back(new dat_api<3>(&mod->ControlUnit_Comparator_6__io_req_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_6.io_req_bits_index"] = 18;
  sim_data.signals.push_back(new dat_api<3>(&mod->ControlUnit_Comparator_6__io_resp_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_6.io_resp_bits_index"] = 19;
  sim_data.signals.push_back(new dat_api<3>(&mod->ControlUnit_Comparator_5__io_req_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_5.io_req_bits_index"] = 20;
  sim_data.signals.push_back(new dat_api<3>(&mod->ControlUnit_Comparator_5__io_resp_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_5.io_resp_bits_index"] = 21;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_4__io_req_bits_feature));
  sim_data.signal_map["ControlUnit.Comparator_4.io_req_bits_feature"] = 22;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_4__io_req_bits_weights));
  sim_data.signal_map["ControlUnit.Comparator_4.io_req_bits_weights"] = 23;
  sim_data.signals.push_back(new dat_api<1>(&mod->ControlUnit_Comparator_4__io_resp_bits_decision));
  sim_data.signal_map["ControlUnit.Comparator_4.io_resp_bits_decision"] = 24;
  sim_data.signals.push_back(new dat_api<3>(&mod->ControlUnit_Comparator_4__io_req_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_4.io_req_bits_index"] = 25;
  sim_data.signals.push_back(new dat_api<3>(&mod->ControlUnit_Comparator_4__io_resp_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_4.io_resp_bits_index"] = 26;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_3__io_req_bits_feature));
  sim_data.signal_map["ControlUnit.Comparator_3.io_req_bits_feature"] = 27;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_3__io_req_bits_weights));
  sim_data.signal_map["ControlUnit.Comparator_3.io_req_bits_weights"] = 28;
  sim_data.signals.push_back(new dat_api<1>(&mod->ControlUnit_Comparator_3__io_resp_bits_decision));
  sim_data.signal_map["ControlUnit.Comparator_3.io_resp_bits_decision"] = 29;
  sim_data.signals.push_back(new dat_api<2>(&mod->ControlUnit_Comparator_3__io_req_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_3.io_req_bits_index"] = 30;
  sim_data.signals.push_back(new dat_api<2>(&mod->ControlUnit_Comparator_3__io_resp_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_3.io_resp_bits_index"] = 31;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_2__io_req_bits_feature));
  sim_data.signal_map["ControlUnit.Comparator_2.io_req_bits_feature"] = 32;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_2__io_req_bits_weights));
  sim_data.signal_map["ControlUnit.Comparator_2.io_req_bits_weights"] = 33;
  sim_data.signals.push_back(new dat_api<1>(&mod->ControlUnit_Comparator_2__io_resp_bits_decision));
  sim_data.signal_map["ControlUnit.Comparator_2.io_resp_bits_decision"] = 34;
  sim_data.signals.push_back(new dat_api<2>(&mod->ControlUnit_Comparator_2__io_req_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_2.io_req_bits_index"] = 35;
  sim_data.signals.push_back(new dat_api<2>(&mod->ControlUnit_Comparator_2__io_resp_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_2.io_resp_bits_index"] = 36;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_1__io_req_bits_feature));
  sim_data.signal_map["ControlUnit.Comparator_1.io_req_bits_feature"] = 37;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_1__io_req_bits_weights));
  sim_data.signal_map["ControlUnit.Comparator_1.io_req_bits_weights"] = 38;
  sim_data.signals.push_back(new dat_api<1>(&mod->ControlUnit_Comparator_1__io_resp_bits_decision));
  sim_data.signal_map["ControlUnit.Comparator_1.io_resp_bits_decision"] = 39;
  sim_data.signals.push_back(new dat_api<1>(&mod->ControlUnit_Comparator_1__io_req_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_1.io_req_bits_index"] = 40;
  sim_data.signals.push_back(new dat_api<1>(&mod->ControlUnit_Comparator_1__io_resp_bits_index));
  sim_data.signal_map["ControlUnit.Comparator_1.io_resp_bits_index"] = 41;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator__io_req_bits_feature));
  sim_data.signal_map["ControlUnit.Comparator.io_req_bits_feature"] = 42;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator__io_req_bits_weights));
  sim_data.signal_map["ControlUnit.Comparator.io_req_bits_weights"] = 43;
  sim_data.signals.push_back(new dat_api<1>(&mod->ControlUnit_Comparator__io_resp_bits_decision));
  sim_data.signal_map["ControlUnit.Comparator.io_resp_bits_decision"] = 44;
  sim_data.signals.push_back(new dat_api<1>(&mod->ControlUnit_Comparator__io_req_bits_index));
  sim_data.signal_map["ControlUnit.Comparator.io_req_bits_index"] = 45;
  sim_data.signals.push_back(new dat_api<1>(&mod->ControlUnit_Comparator__io_resp_bits_index));
  sim_data.signal_map["ControlUnit.Comparator.io_resp_bits_index"] = 46;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_5__io_req_bits_feature));
  sim_data.signal_map["ControlUnit.Comparator_5.io_req_bits_feature"] = 47;
  sim_data.signals.push_back(new dat_api<32>(&mod->ControlUnit_Comparator_5__io_req_bits_weights));
  sim_data.signal_map["ControlUnit.Comparator_5.io_req_bits_weights"] = 48;
  sim_data.signals.push_back(new dat_api<1>(&mod->ControlUnit_Comparator_5__io_resp_bits_decision));
  sim_data.signal_map["ControlUnit.Comparator_5.io_resp_bits_decision"] = 49;
  sim_data.clk_map["clk"] = new clk_api(&mod->clk);
}
