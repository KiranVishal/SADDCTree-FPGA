package saddc

import Chisel._

case object Max_Depth extends Field[Int]
case object Max_Features extends Field[Int]
case object Min_Samples_Split extends Field[Int]
case object Min_Samples_Leaf extends Field[Int]
case object Max_Leaf_Node extends Field[Int]
case object Min_Impurity_Split extends Field[Float]


abstract trait SADDCParameters extends UsesParameters {
  val max_depth = params(Max_Depth)
  val max_features = params(Max_Features)
  val min_samples_split = params(Min_Samples_Split)
  val min_samples_leaf = params(Min_Samples_Leaf)
  val max_leaf_node = params(Max_Leaf_Node)
  val min_impurity_split = params(Min_Impurity_Split)
}

// An abstract base class for anything associated with SADDC
abstract class SADDCModule extends Module with SADDCParameters

// Base class for all Bundle classes used in SADDC. This sets all the
// parameters that should be shared. All parameters defined here
// should be the same as in SADDCModule.
abstract class SADDCBundle extends Bundle with SADDCParameters