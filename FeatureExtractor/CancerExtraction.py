"""
=========================================
Understanding the decision tree structure
=========================================
The decision tree structure can be analysed to gain further insight on the
relation between the features and the target to predict. In this example, we
show how to retrieve:
- the binary tree structure;
- the depth of each node and whether or not it's a leaf;
- the nodes that were reached by a sample using the ``decision_path`` method;
- the leaf that was reached by a sample using the apply method;
- the rules that were used to predict a sample;
- the decision path shared by a group of samples.
"""
import sys
sys.path.append("/Users/marcia/SADDCTree-FPGA")

import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
import breastCancer
from DecisionTreeVisualizer import DT_Visualizer

X,y, feature_names, target_names = breastCancer.load_data("./dataSet/breast-cancer-wisconsin.data.txt")
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=0)

estimator = DecisionTreeClassifier()
estimator.fit(X_train, y_train)


# The decision estimator has an attribute called tree_  which stores the entire
# tree structure and allows access to low level attributes. The binary tree
# tree_ is represented as a number of parallel arrays. The i-th element of each
# array holds information about the node `i`. Node 0 is the tree's root. NOTE:
# Some of the arrays only apply to either leaves or split nodes, resp. In this
# case the values of nodes of the other type are arbitrary!
#
# Among those arrays, we have:
#   - left_child, id of the left child of the node
#   - right_child, id of the right child of the node
#   - feature, feature used for splitting the node
#   - threshold, threshold value at the node
#

# Using those arrays, we can parse the tree structure:

n_nodes = estimator.tree_.node_count
children_left = estimator.tree_.children_left
children_right = estimator.tree_.children_right
feature = estimator.tree_.feature
threshold = estimator.tree_.threshold


# The tree structure can be traversed to compute various properties such
# as the depth of each node and whether or not it is a leaf.
node_depth = np.zeros(shape=n_nodes)
is_leaves = np.zeros(shape=n_nodes, dtype=bool)
stack = [(0, -1)]  # seed is the root node id and its parent depth
while len(stack) > 0:
    node_id, parent_depth = stack.pop()
    node_depth[node_id] = parent_depth + 1

    # If we have a test node
    if (children_left[node_id] != children_right[node_id]):
        stack.append((children_left[node_id], parent_depth + 1))
        stack.append((children_right[node_id], parent_depth + 1))
    else:
        is_leaves[node_id] = True

print("The binary tree structure has %s nodes and has "
      "the following tree structure:"
      % n_nodes)
for i in range(n_nodes):
    if is_leaves[i]:
        print("%snode=%s leaf node." % (node_depth[i] * "\t", i))
    else:
        print("%snode=%s test node: go to node %s if X[:, %s] <= %ss else to "
              "node %s."
              % (node_depth[i] * "\t",
                 i,
                 children_left[i],
                 feature[i],
                 threshold[i],
                 children_right[i],
                 ))
print()

# Write Network Structure to a file
import csv

feature_writer = csv.writer(open('./FeatureExtractor/FE_Cancer.csv','w'),delimiter=' ', quotechar='|')
feature_writer.writerow(['NodeID', 'LeftNode', 'RightNode', 'FeatureId', 'Threshold'])
for i in range(n_nodes):
    if is_leaves[i]:
        # -5 for leaf nodes to differentiate them and also to not leave blank fields
        feature_writer.writerow([i, -5, -5, feature[i], threshold[i]]) 
    else:
        feature_writer.writerow([i, children_left[i], children_right[i], feature[i], threshold[i]])

#testing 

from sklearn.metrics import accuracy_score
y_pred = estimator.predict(X_test)

print('Test Accuracy',accuracy_score(y_test, y_pred))

# Graph Visualization
import pydotplus

dot_data = DT_Visualizer.getDotFile(estimator, feature_names,target_names)
graph = pydotplus.graph_from_dot_data(dot_data.getvalue())
graph.write_pdf("./DecisionTreeVisualizer/Cancer.pdf")