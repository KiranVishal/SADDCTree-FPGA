# FOR GRAGH VISUALIZATION 

from sklearn.externals.six import StringIO
import pydotplus

from sklearn.tree import export_graphviz

def getDotFile(estimator, feature_names=None, target_names=None):
	dot_data = StringIO()
	export_graphviz(estimator, 
	                        out_file=dot_data, 
	                        feature_names=feature_names,  
	                        class_names=target_names,  
	                        filled=True, rounded=True,  
	                        impurity=False)
	#dot_data = DT_Visualizer.getDotFile(estimator, feature_names,target_names)
	graph = pydotplus.graph_from_dot_data(dot_data.getvalue())
	graph.write_pdf("./paper/Tree_visuals/Cancer.pdf")


# FOR FEATURE EXTRACTION

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

	n_leaf = 0 
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
	
	for i in range(n_nodes):
	    if is_leaves[i]:
	    	n_leaf = n_leaf + 1
	#Make Sure The File Name  Has The Extension .CSV
	#File_used = FileName
	n_nonleaf = n_nodes - n_leaf
	feature_writer = csv.writer(open(FileName,'w'),delimiter=' ', quotechar='|')
	#feature_writer.writerow(['N_Node', 'Left_Node', 'Nonleaf_Node'])
	feature_writer.writerow([n_nodes, n_leaf, n_nonleaf])
	#feature_writer.writerow(['NodeID', 'LeftNode', 'RightNode', 'FeatureId', 'Threshold'])
	for i in range(n_nodes):
	    if is_leaves[i]:
	        # -5 for leaf nodes to differentiate them and also to not leave blank fields
	        feature_writer.writerow([i, -5, -5, feature[i], threshold[i]]) 
	    else:
	        feature_writer.writerow([i, children_left[i], children_right[i], feature[i], threshold[i]])


