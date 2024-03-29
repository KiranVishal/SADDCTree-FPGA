import numpy as np
from sklearn.datasets import load_iris
from sklearn import tree

#loading the dataset
iris = load_iris()

# print (iris.feature_names)
# print (iris.target_names)
# print (iris.data[0])
# print (iris.target[0])

test_idx = [0,50,100]

#training data

train_target = np.delete(iris.target, test_idx)
train_data = np.delete(iris.data, test_idx, axis=0)

#testing data

test_target = iris.target[test_idx]
test_data = iris.data[test_idx]

# Creating the DT classifier

clf = tree.DecisionTreeClassifier()

# Training the model

clf.fit(train_data, train_target)


#Testing the model

print (test_target)

print (clf.predict(test_data))

# Graph Visualization

from sklearn.externals.six import StringIO

import pydotplus

dot_data = StringIO()
tree.export_graphviz(clf, 
						out_file=dot_data, 
                        feature_names=iris.feature_names,  
                        class_names=iris.target_names,  
                        filled=True, rounded=True,  
                        impurity=False)

graph = pydotplus.graph_from_dot_data(dot_data.getvalue())
graph.write_pdf("iris.pdf")

# from IPython.display import Image
# from sklearn.externals.six import StringIO

# dot_data = StringIO() 
# tree.export_graphviz(clf, out_file=dot_data, 
#                          feature_names=iris.feature_names,  
#                          class_names=iris.target_names,  
#                          filled=True, rounded=True,  
#                          impurity=False)  
# graph = pydotplus.graph_from_dot_data(dot_data)  
# Image(graph.create_png())

















