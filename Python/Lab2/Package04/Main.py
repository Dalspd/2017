import random
import time
import sys

from Package04.Sort import Sort

sys.setrecursionlimit(200)  # 控制递归时间

list1 = []
for x in range(0, 1000):
	list1.append(random.randint(0, 100))
sort1 = Sort(list1)
t1 = time.clock()
print(sort1.bubbleSort())
t2 = time.clock()
print("Bubble Sort-Time:", t2 - t1)

list2 = []
for y in range(0, 1000):
	list2.append(random.randint(0, 100))
sort2 = Sort(list2)
t1 = time.clock()
print(sort2.quickSort(0, len(list2) - 1))
t2 = time.clock()
print("Quick Sort-Time:", t2 - t1)
