import os
import numpy as np
import random

class InputData:
	TEST_DB_SIZE = 2000

	sketches = []
	labels = []
	types = None

	def __init__(self):
		self.read_labels('data/labels')
		self.types = list(set(self.labels))
		self.types.sort()

		self.read_sketches('data/sketches')
		indexes = [i for i in range(len(self.sketches))]
		random.shuffle(indexes)

		self.train_indexes = indexes[self.TEST_DB_SIZE:]
		self.test_indexes = indexes[:self.TEST_DB_SIZE]

		self.train_i = 0
		self.test_i = 0

		print('data loading ready')

	def read_labels(self, filename):
		with open(filename, 'r') as f:
			for line in f:
				self.labels.append(line.split('/')[0])

	def read_sketches(self, filename):
		f = open(filename, 'r')
		f.readline()
		f.readline()
		for line in f:
			self.sketches.append(np.array([float(i) for i in line.split(' ')[:-1]]))
		f.close()

	def one_hot(self, label):
		r = np.zeros(len(self.types))
		r[self.types.index(label)] = 1
		return r

	def rewind(self):
		self.train_i = 0
		self.test_i = 0

	def train_next_batch(self, size):
		if self.train_i > len(self.train_indexes):
			return None, None
		indexes = self.train_indexes[self.train_i:self.train_i+size]
		self.train_i += size
		batch_sketches, batch_labels = [], []
		for i in indexes:
			batch_sketches.append(self.sketches[i])
			batch_labels.append(self.one_hot(self.labels[i]))
		return batch_sketches, batch_labels

	def test_next_batch(self, size):
		if self.test_i > len(self.test_indexes):
			return None, None
		indexes = self.test_indexes[self.test_i:self.test_i+size]
		self.test_i += size
		batch_sketches, batch_labels = [], []
		for i in indexes:
			batch_sketches.append(self.sketches[i])
			batch_labels.append(self.one_hot(self.labels[i]))
		return batch_sketches, batch_labels

input_data = InputData()

# if __name__ == '__main__':
# 	print(input_data.test_next_batch(1))