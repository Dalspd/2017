from random import random

hits = 0.0
a = 10
b = 8

for x in range(10,20):
	darts=2**x
	print("darts=",darts)
	for i in range(0, darts):
		x, y = a * random() / 2, b * random() / 2
		if x * x / (a * a / 4) + y * y / (b * b / 4) <= 1.0:
			hits += 1
	print("Simulated area is:", a * b * hits / darts)
