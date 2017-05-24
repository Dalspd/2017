class Sort():
	def __init__(self, list):
		self.list = list

	def bubbleSort(self):  # 冒泡排序
		for i in range(len(self.list)):
			for j in range(len(self.list) - i - 1):
				if self.list[j] > self.list[j + 1]:
					(self.list[j], self.list[j + 1]) = (self.list[j + 1], self.list[j])
		return self.list

	def quickSort(self, l, r):  # 快速排序
		if l >= r:  # 如果只有一个数字时，结束递归
			return
		flag = l
		for i in range(l + 1, r + 1):  # 默认以第一个数字作为基准数，从第二个数开始比较，生成索引时要注意右部的值
			if self.list[flag] > self.list[i]:
				tmp = self.list[i]
				del self.list[i]
				self.list.insert(flag, tmp)
				flag += 1
		self.quickSort(l, flag - 1)  # 将基准数前后部分分别递归排序
		self.quickSort(flag + 1, r)
		return self.list
