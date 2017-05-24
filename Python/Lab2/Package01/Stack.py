class Stack():
	def __init__(self, size):
		self.size = size
		self.stack = []
		self.top = -1

	def isfull(self):
		return self.top + 1 == self.size

	def isempty(self):
		return self.top == -1

	def printAll(self):
		if self.isempty():
			raise Exception("Stack is empty.")
		else:
			print(self.stack)

	def peekstack(self):
		if self.isempty():
			raise Exception("Stack is empty.")
		else:
			print(self.top)

	def pushstack(self, x):
		if self.isfull():
			raise Exception("Stack is full.")
		else:
			self.stack.append(x)
			self.top += 1

	def popstack(self):
		if self.isempty():
			raise Exception("Stack is empty.")
		else:
			self.top -= 1
			self.stack.pop()
