#include "Comparator.DefaultSADDCConfig.h"

void Comparator_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  Comparator__dataOut.randomize(&__rand_seed);
  clk.len = 1;
  clk.cnt = 0;
  clk.values[0] = 0;
}


int Comparator_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk.cnt < min) min = clk.cnt;
  clk.cnt-=min;
  if (clk.cnt == 0) clock_lo( reset );
  if (!reset.to_bool()) print( std::cerr );
  if (clk.cnt == 0) clock_hi( reset );
  if (clk.cnt == 0) clk.cnt = clk.len;
  return min;
}


void Comparator_t::print ( FILE* f ) {
}
void Comparator_t::print ( std::ostream& s ) {
}


void Comparator_t::dump_init ( FILE* f ) {
}


void Comparator_t::dump ( FILE* f, val_t t, dat_t<1> reset ) {
}




void Comparator_t::clock_lo ( dat_t<1> reset, bool assert_fire ) {
  { val_t __r = this->__rand_val(); Comparator__io_req_ready.values[0] = __r;}
  Comparator__io_req_ready.values[0] = Comparator__io_req_ready.values[0] & 0x1L;
  { val_t __r = this->__rand_val(); Comparator__io_resp_valid.values[0] = __r;}
  Comparator__io_resp_valid.values[0] = Comparator__io_resp_valid.values[0] & 0x1L;
  val_t T0;
  T0 = (Comparator__io_req_bits_feature.values[0] >> 31) & 1;
  val_t T1;
  T1 = Comparator__io_req_bits_feature.values[0]<=Comparator__io_req_bits_weights.values[0];
  val_t T2;
  T2 = (Comparator__io_req_bits_weights.values[0] >> 31) & 1;
  val_t T3;
  T3 = T0 == T2;
  val_t T4;
  { T4 = TERNARY_1(T3, T1, T0);}
  val_t T5;
  { T5 = TERNARY(T4, 0x1L, Comparator__dataOut.values[0]);}
  val_t T6;
  { T6 = T4 ^ 0x1L;}
  { T7.values[0] = TERNARY(T6, 0x0L, T5);}
  { Comparator__io_resp_bits_decision.values[0] = Comparator__dataOut.values[0];}
}


void Comparator_t::clock_hi ( dat_t<1> reset ) {
  dat_t<1> Comparator__dataOut__shadow = T7;
  Comparator__dataOut = T7;
}


void Comparator_api_t::init_sim_data (  ) {
  sim_data.inputs.clear();
  sim_data.outputs.clear();
  sim_data.signals.clear();
  Comparator_t* mod = dynamic_cast<Comparator_t*>(module);
  assert(mod);
  sim_data.inputs.push_back(new dat_api<1>(&mod->Comparator__io_req_valid));
  sim_data.inputs.push_back(new dat_api<32>(&mod->Comparator__io_req_bits_feature));
  sim_data.inputs.push_back(new dat_api<32>(&mod->Comparator__io_req_bits_weights));
  sim_data.inputs.push_back(new dat_api<1>(&mod->Comparator__io_resp_ready));
  sim_data.outputs.push_back(new dat_api<1>(&mod->Comparator__io_req_ready));
  sim_data.outputs.push_back(new dat_api<1>(&mod->Comparator__io_resp_valid));
  sim_data.outputs.push_back(new dat_api<1>(&mod->Comparator__io_resp_bits_decision));
  sim_data.signals.push_back(new dat_api<1>(&mod->Comparator__dataOut));
  sim_data.signal_map["Comparator.dataOut"] = 0;
  sim_data.clk_map["clk"] = new clk_api(&mod->clk);
}
