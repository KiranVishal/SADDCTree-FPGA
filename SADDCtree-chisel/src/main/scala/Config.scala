package saddc

import Chisel._


class DefaultSADDCConfig extends ChiselConfig (
  topDefinitions = { (pname,site,here) =>
    pname match {
      case No_Comparator => Dump(Knob("n_comparators"))
      // case No_Nodes => 10
      // case No_Leaf => 5
      // case Max_Depth => 4
      // case Max_Features => 4
      // case Min_Samples_Split => 2
      // case Min_Samples_Leaf => 1
      // case Max_Leaf_Node => 3
      // case Min_Impurity_Split => 1e-7
    }},
  knobValues = {
    // Varibles that depend on the decision trees

    // For now it is equal to n_nodes-n_leaf in the network read it from file
    case "n_comparators" => 10
    // case "max_depth" => 4
    // case "max_features" => 4
    // case "min_samples_split" => 2
    // case "min_samples_leaf" => 1
    // case "max_leaf_node" => 3
    // case "min_impurity_split" => 1e-7
  }
)
class DefaultSADDCFPGAConfig extends ChiselConfig(new DefaultSADDCConfig)