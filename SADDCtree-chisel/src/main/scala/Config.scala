package saddc

import Chisel._


class DefaultSADDCConfig extends ChiselConfig (
  topDefinitions = { (pname,site,here) =>
    pname match {
      case Max_Depth => Dump(Knob("max_depth"))
      case Max_Features => Dump(Knob("max_features"))
      case Min_Samples_Split => Dump(Knob("min_samples_split"))
      case Min_Samples_Leaf => Dump(Knob("min_samples_leaf"))
      case Max_Leaf_Node => Dump(Knob("max_leaf_node"))
      case Min_Impurity_Split => Dump(Knob("min_impurity_split"))
    }},
  knobValues = {
    // Varibles that depebd on the decision trees
    case "max_depth" => 4
    case "max_features" => 4
    case "min_samples_split" => 2
    case "min_samples_leaf" => 1
    case "max_leaf_node" => 3
    case "min_impurity_split" => 1e-7
  }
)
class DefaultSADDCFPGAConfig extends ChiselConfig(new DefaultSADDCConfig)