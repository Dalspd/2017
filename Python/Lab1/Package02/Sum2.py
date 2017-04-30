import random

aList = []
for i in range(0, 101):
	aList.append(i)
sList = random.sample(aList, 10)
print("符合条件1的元素:", sList)
new_sList = []
for i in range(0, len(sList)):
	if sList[i] % 3 == 0 and sList[i] % 2 == 1:
		new_sList.append(sList[i])
print("符合条件1，2的元素:", new_sList)
sum = 0
for i in range(0, len(new_sList)):
	sum += new_sList[i]
print("这些元素的和为:%d" % sum)
