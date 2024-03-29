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
import numpy as np

from sklearn.model_selection import train_test_split
from sklearn.datasets import load_digits
from sklearn.tree import DecisionTreeClassifier
# import pdb

digits = load_digits()
# test_idx = [0,50,100]
X = digits.data
y = digits.target
# X_train = np.delete(X, test_idx,axis=0)
# y_train = np.delete(y, test_idx)
# X_test = X[test_idx]
# y_test = y[test_idx]
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=0)

estimator = DecisionTreeClassifier()
estimator.fit(X_train, y_train)

#Testing the model

print (y_test)

print (estimator.predict(X_test))
y_pred = estimator.predict(X_test)
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
#pdb.set_trace()
# n_nodes = estimator.tree_.node_count
# children_left = estimator.tree_.children_left
# children_right = estimator.tree_.children_right
# feature = estimator.tree_.feature
# threshold = estimator.tree_.threshold
#pdb.set_trace()

# print(feature)
# # The tree structure can be traversed to compute various properties such
# # as the depth of each node and whether or not it is a leaf.
# node_depth = np.zeros(shape=n_nodes)
# is_leaves = np.zeros(shape=n_nodes, dtype=bool)
# stack = [(0, -1)]  # seed is the root node id and its parent depth
# while len(stack) > 0:
#     node_id, parent_depth = stack.pop()
#     node_depth[node_id] = parent_depth + 1

    # If we have a test node
#     if (children_left[node_id] != children_right[node_id]):
#         stack.append((children_left[node_id], parent_depth + 1))
#         stack.append((children_right[node_id], parent_depth + 1))
#     else:
#         is_leaves[node_id] = True

# print("The binary tree structure has %s nodes and has "
#       "the following tree structure:"
#       % n_nodes)
# for i in range(n_nodes):
#     if is_leaves[i]:
#         print("%snode=%s leaf node." % (node_depth[i] * "\t", i))
#     else:
#         print("%snode=%s test node: go to node %s if X[:, %s] <= %ss else to "
#               "node %s."
#               % (node_depth[i] * "\t",
#                  i,
#                  children_left[i],
#                  feature[i],
#                  threshold[i],
#                  children_right[i],
#                  ))
# print()

# import csv

# feature_writer = csv.writer(open('FE_Digits.csv','w'),delimiter=' ', quotechar='|')
# feature_writer.writerow(['NodeID', 'LeftNode', 'RightNode', 'FeatureId', 'Threshold'])
# for i in range(n_nodes):
#     if is_leaves[i]:
#         # -5 for leaf nodes to differentiate them and also to not leave blank fields
#         feature_writer.writerow([i, -5, -5, feature[i], threshold[i]]) 
#     else:
#         feature_writer.writerow([i, children_left[i], children_right[i], feature[i], threshold[i]])


# First let's retrieve the decision path of each sample. The decision_path
# method allows to retrieve the node indicator functions. A non zero element of
# indicator matrix at the position (i, j) indicates that the sample i goes
# through the node j.

# node_indicator = estimator.decision_path(X_test)
# print("node_indicator %s" % node_indicator)

# Similarly, we can also have the leaves ids reached by each sample.

# leave_id = estimator.apply(X_test)

# # Now, it's possible to get the tests that were used to predict a sample or
# # a group of samples. First, let's make it for the sample.

# for sample_id in range(len(y_test)):
#     # sample_id = 0
#     node_index = node_indicator.indices[node_indicator.indptr[sample_id]:
#                                         node_indicator.indptr[sample_id + 1]]

#     print('Rules used to predict sample %s: ' % sample_id)
#     for node_id in node_index:
#         if leave_id[sample_id] != node_id:
#             continue

#         if (X_test[sample_id, feature[node_id]] <= threshold[node_id]):
#             threshold_sign = "<="
#         else:
#             threshold_sign = ">"

#         print("decision id node %s : (X[%s, %s] (= %s) %s %s)"
#               % (node_id,
#                  sample_id,
#                  feature[node_id],
#                  X_test[sample_id, feature[node_id]],
#                  threshold_sign,
#                  threshold[node_id]))

# from sklearn.metrics import accuracy_score
# y_pred = estimator.predict(X_test)

# print(accuracy_score(y_test, y_pred))

# Graph Visualization

from sklearn.externals.six import StringIO

import pydotplus

from sklearn.tree import export_graphviz

#pdb.set_trace()
dot_data = StringIO()
feature_list = [range(64)]
# print(digits.target_names)
export_graphviz(estimator, 
                        out_file=dot_data,   
                        class_names=str(digits.target_names),
                        rounded = True, filled = True,
                        impurity = False
                        )

graph = pydotplus.graph_from_dot_data(dot_data.getvalue())
graph.write_pdf("digits.pdf")
#pdb.set_trace()

# Finding the score:
from sklearn.metrics import accuracy_score
# y_pred = estimator.predict(X_test)
print("The prediction Score is:")
print(accuracy_score(y_test, y_pred))
    
# # For a group of samples, we have the following common node.
# sample_ids = [0, 1]
# common_nodes = (node_indicator.toarray()[sample_ids].sum(axis=0) ==
#                 len(sample_ids))

# common_node_id = np.arange(n_nodes)[common_nodes]

# print("\nThe following samples %s share the node %s in the tree"
#       % (sample_ids, common_node_id))
# print("It is %s %% of all nodes." % (100 * len(common_node_id) / n_nodes,))
