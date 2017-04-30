import random


def sum1():
	return random.randint(0, 101)


def sum2(x):
	if x % 3 == 0 and x % 2 == 1:
		return x


sSet = set()
while len(sSet) < 10:
	sSet.add(sum1())
print("符合条件1的元素:", sSet)
new_sSet = set()
sum = 0
for x in sSet:
	new_sSet.add(sum2(x))
sum = 0
if len(new_sSet) > 1:
	new_sSet.remove(None)
	for x in new_sSet:
		sum += x
print("符合条件1，2的元素:", new_sSet)
print("这些元素的和为:%d" % sum)
