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