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
sys.path.append("./paper")

import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
import breastCancer
from custom_imports import DT_Helpers


X,y, feature_names, target_names = breastCancer.load_data("./dataSet/breast-cancer-wisconsin.data.txt")
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=0)

estimator = DecisionTreeClassifier()
estimator.fit(X_train, y_train)

DT_Helpers.getFeaturesFile(estimator, './paper/Trained_nets/FE_Cancer.train')
DT_Helpers.getDotFile(estimator, feature_names,target_names)