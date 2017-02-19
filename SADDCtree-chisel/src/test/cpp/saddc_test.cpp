#include "saddc_test.h"

saddc_model::saddc_model() {
  num_input = 0; //*To-Do* read from file
  num_output = 0;  //*To-Do* read from file
  count_in = 0;
  count_out = 0;
  count_reads = 0;
  inputs.resize(num_input);
  outputs.resize(num_output);
  for (int i = 0; i < num_input; i++)
    inputs[i] = (int32_t) (_inputs[i]); // *To-Do* _input is read from file
  //fann_type * tmp = fann_run(ann, _inputs);
  for (int i = 0; i < num_output; i++)
    outputs_fann[i] = tmp[i]; // *To-Do* expected output is read from file
};

bool transaction::new_read() {
  count_reads++;
  return count_reads == num_output;
};

int32_t transaction::get_input() {
  return inputs[count_in++];
};

bool transaction::done_in() {
  return count_in == num_input - 1;
};

bool transaction::done_out() {
  return outputs.size() == num_output;
};