#ifndef __ControlUnit__
#define __ControlUnit__

#include "emulator.h"

class ControlUnit_t : public mod_t {
 private:
  val_t __rand_seed;
  void __srand(val_t seed) { __rand_seed = seed; }
  val_t __rand_val() { return ::__rand_val(&__rand_seed); }
 public:
  dat_t<1> ControlUnit_Comparator_9__io_req_ready;
  dat_t<1> ControlUnit_Comparator_9__io_resp_valid;
  dat_t<1> ControlUnit_Comparator_9__io_resp_bits_decision;
  dat_t<1> ControlUnit_Comparator_8__io_req_ready;
  dat_t<1> ControlUnit_Comparator_8__io_resp_valid;
  dat_t<1> ControlUnit_Comparator_8__io_resp_bits_decision;
  dat_t<1> ControlUnit_Comparator_7__io_req_ready;
  dat_t<1> ControlUnit_Comparator_7__io_resp_valid;
  dat_t<1> ControlUnit_Comparator_7__io_resp_bits_decision;
  dat_t<1> ControlUnit_Comparator_6__io_req_ready;
  dat_t<1> ControlUnit_Comparator_6__io_resp_valid;
  dat_t<1> ControlUnit_Comparator_6__io_resp_bits_decision;
  dat_t<1> ControlUnit_Comparator_5__io_req_ready;
  dat_t<1> ControlUnit_Comparator_5__io_resp_valid;
  dat_t<1> ControlUnit_Comparator_4__io_req_ready;
  dat_t<1> ControlUnit_Comparator_4__io_resp_valid;
  dat_t<1> ControlUnit_Comparator_4__io_resp_bits_decision;
  dat_t<1> ControlUnit_Comparator_3__io_req_ready;
  dat_t<1> ControlUnit_Comparator_3__io_resp_valid;
  dat_t<1> ControlUnit_Comparator_3__io_resp_bits_decision;
  dat_t<1> ControlUnit_Comparator_2__io_req_ready;
  dat_t<1> ControlUnit_Comparator_2__io_resp_valid;
  dat_t<1> ControlUnit_Comparator_2__io_resp_bits_decision;
  dat_t<1> ControlUnit_Comparator_1__io_req_ready;
  dat_t<1> ControlUnit_Comparator_1__io_resp_valid;
  dat_t<1> ControlUnit_Comparator_1__io_resp_bits_decision;
  dat_t<1> ControlUnit_Comparator_1__io_req_bits_index;
  dat_t<1> ControlUnit_Comparator_1__io_resp_bits_index;
  dat_t<1> ControlUnit_Comparator__io_req_ready;
  dat_t<1> ControlUnit_Comparator__io_resp_valid;
  dat_t<1> ControlUnit_Comparator__io_resp_bits_decision;
  dat_t<1> ControlUnit_Comparator__io_req_bits_index;
  dat_t<1> ControlUnit_Comparator__io_resp_bits_index;
  dat_t<1> ControlUnit_Comparator_5__io_resp_bits_decision;
  dat_t<1> ControlUnit__io_decision;
  dat_t<2> ControlUnit_Comparator_3__io_req_bits_index;
  dat_t<2> ControlUnit_Comparator_3__io_resp_bits_index;
  dat_t<2> ControlUnit_Comparator_2__io_req_bits_index;
  dat_t<2> ControlUnit_Comparator_2__io_resp_bits_index;
  dat_t<3> ControlUnit_Comparator_7__io_req_bits_index;
  dat_t<3> ControlUnit_Comparator_7__io_resp_bits_index;
  dat_t<3> ControlUnit_Comparator_6__io_req_bits_index;
  dat_t<3> ControlUnit_Comparator_6__io_resp_bits_index;
  dat_t<3> ControlUnit_Comparator_5__io_req_bits_index;
  dat_t<3> ControlUnit_Comparator_5__io_resp_bits_index;
  dat_t<3> ControlUnit_Comparator_4__io_req_bits_index;
  dat_t<3> ControlUnit_Comparator_4__io_resp_bits_index;
  dat_t<4> ControlUnit_Comparator_9__io_req_bits_index;
  dat_t<4> ControlUnit_Comparator_9__io_resp_bits_index;
  dat_t<4> ControlUnit_Comparator_8__io_req_bits_index;
  dat_t<4> ControlUnit_Comparator_8__io_resp_bits_index;
  dat_t<32> ControlUnit__io_fBlock;
  dat_t<32> ControlUnit_Comparator_9__io_req_bits_feature;
  dat_t<32> ControlUnit__io_wBlock;
  dat_t<32> ControlUnit_Comparator_9__io_req_bits_weights;
  dat_t<32> ControlUnit_Comparator_8__io_req_bits_feature;
  dat_t<32> ControlUnit_Comparator_8__io_req_bits_weights;
  dat_t<32> ControlUnit_Comparator_7__io_req_bits_feature;
  dat_t<32> ControlUnit_Comparator_7__io_req_bits_weights;
  dat_t<32> ControlUnit_Comparator_6__io_req_bits_feature;
  dat_t<32> ControlUnit_Comparator_6__io_req_bits_weights;
  dat_t<32> ControlUnit_Comparator_4__io_req_bits_feature;
  dat_t<32> ControlUnit_Comparator_4__io_req_bits_weights;
  dat_t<32> ControlUnit_Comparator_3__io_req_bits_feature;
  dat_t<32> ControlUnit_Comparator_3__io_req_bits_weights;
  dat_t<32> ControlUnit_Comparator_2__io_req_bits_feature;
  dat_t<32> ControlUnit_Comparator_2__io_req_bits_weights;
  dat_t<32> ControlUnit_Comparator_1__io_req_bits_feature;
  dat_t<32> ControlUnit_Comparator_1__io_req_bits_weights;
  dat_t<32> ControlUnit_Comparator__io_req_bits_feature;
  dat_t<32> ControlUnit_Comparator__io_req_bits_weights;
  dat_t<32> ControlUnit_Comparator_5__io_req_bits_feature;
  dat_t<32> ControlUnit_Comparator_5__io_req_bits_weights;
  dat_t<32> ControlUnit__io_optN_comp;
  dat_t<32> ControlUnit__io_feature_index;
  dat_t<32> ControlUnit__io_right_node;
  dat_t<32> ControlUnit__io_left_node;
  dat_t<32> ControlUnit__io_current_node;
  dat_t<32> ControlUnit__io_nonleaf_node;
  dat_t<32> ControlUnit__io_leaf_node;
  dat_t<32> ControlUnit__io_n_node;
  clk_t clk;

  void init ( val_t rand_init = 0 );
  void clock_lo ( dat_t<1> reset, bool assert_fire=true );
  void clock_hi ( dat_t<1> reset );
  int clock ( dat_t<1> reset );
  void print ( FILE* f );
  void print ( std::ostream& s );
  void dump ( FILE* f, val_t t, dat_t<1> reset=LIT<1>(0) );
  void dump_init ( FILE* f );

};

#include "emul_api.h"
class ControlUnit_api_t : public emul_api_t {
 public:
  ControlUnit_api_t(mod_t* m) : emul_api_t(m) { }
  void init_sim_data();
};

#endif