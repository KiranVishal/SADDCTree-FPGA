import numpy as np
import re


def load_data(data):
	f = open(data, 'r')
	feature_names = ['Clump Thickness', 'Uniformity of Cell Size', 'Uniformity of Cell Shape', 'Marginal Adhesion', 'Single Epithelial Cell Size', 'Bare Nuclei', 'Bland Chromatin', 'Normal Nucleoli', 'Mitoses']
	target_names = ['benign','malignant']
	
	data = []
	label = []

	for line in f:
	    line = line.split('\n')[0]
	    line = line.split(',')
	    data.append(line[1:-2])
	    label.append(line[-1])

	data = np.asarray(data)
	label = np.asarray(label)
	return data, label, feature_names, target_names 

