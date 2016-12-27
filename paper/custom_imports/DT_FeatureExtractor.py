import numpy as np
import csv
#Import Decision Tree Library from Sklearn
from sklearn.tree import DecisionTreeClassifier

def getFeaturesFile(estimator, FileName):

	#The information need to build the decision tree
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

	#Make Sure The File Name  Has The Extension .CSV
	#File_used = FileName
	feature_writer = csv.writer(open(FileName,'w'),delimiter=' ', quotechar='|')
	feature_writer.writerow(['NodeID', 'LeftNode', 'RightNode', 'FeatureId', 'Threshold'])
	for i in range(n_nodes):
	    if is_leaves[i]:
	        # -5 for leaf nodes to differentiate them and also to not leave blank fields
	        feature_writer.writerow([i, -5, -5, feature[i], threshold[i]]) 
	    else:
	        feature_writer.writerow([i, children_left[i], children_right[i], feature[i], threshold[i]])


