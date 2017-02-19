// Transaction class that encapsulates a single transaction, i.e., a
// request by a thread to compute the output of neural network
// (specified by an NNID) for a given input vector.

class saddc_model {
private:
  unsigned int count_in, count_out, count_reads;
  //int output_fann_th, output_dana_th;

public:
  //struct fann * ann;
  unsigned int num_input, num_output;
  std::vector<int32_t> inputs;
  std::vector<int32_t> outputs;
  uint16_t num_rounds;

  saddc_model();
  int32_t get_input();
  bool done_in();
  bool done_out();
  bool new_read();
  //void update_error(double);
};
