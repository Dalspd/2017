import string


class Queue():
	def __init__(self, size):
		self.size = size
		self.front = -1
		self.rear = -1
		self.queue = []

	def isempty(self):
		return self.front == self.rear

	def isfull(self):
		return self.rear - self.front + 1 == self.size

	def enqueue(self, x):
		if self.isfull():
			raise Exception("Queue is full.")
		else:
			self.queue.append(x)
			self.rear += 1

	def dequeue(self):
		if self.isempty():
			raise Exception("Queue is empty.")
		else:
			self.queue.pop(0)
			self.front += 1

	def printAll(self):
		if self.isempty():
			raise Exception("Queue is empty.")
		else:
			print(self.queue)

	def putfile(self, file):
		file_object = open(file, "w")
		file_object.write(str(self.queue))

	def getfile(self, file):
		file_object = open(file, "r")
		self.enqueue(file_object.readline())
