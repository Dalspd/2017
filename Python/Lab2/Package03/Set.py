class Set():
	def __init__(self,list):
		self.set=[]
		for x in list:
			if x not in self.set:
				self.set.append(x)

	def addElement(self,x):
		if x in self.set:
			print("Element already exists.")
		else:
			self.set.append(x)

	def deleteElement(self,x):
		if x in self.set:
			self.set.remove(x)
		else:
			raise Exception("Element not in the set.")

	def isMember(self,x):
		if x in self.set:
			return True
		else:
			return False

	def intersection(self,set2):
		tmp=list(self.set)
		for x in self.set:
			if x not in set2.set:
				tmp.remove(x)
		return tmp

	def union(self,set2):
		tmp=list(self.set)
		for x in set2.set:
			if x not in tmp:
				tmp.append(x)
		return tmp

	def subtract(self,set2):
		tmp=list(self.set)
		for x in set2.set:
			if x  in tmp:
				tmp.remove(x)
		return tmp

	def printAll(self):
		if self.set.__len__()==0:
			raise Exception("Set is Null.")
		else:
			print(self.set)