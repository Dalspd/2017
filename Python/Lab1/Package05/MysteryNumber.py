import random


def add(lista):
	sum = 0
	for x in range(0, 4):
		sum += lista[x] * (10 ** (3 - x))
	return sum


def mys(a):
	lista = [a // 1000, a // 100 % 10, a // 10 % 10, a % 10]
	l1 = sorted(lista)
	min = add(l1)
	l2 = sorted(l1)
	l2.reverse()
	max = add(l2)
	return max - min


n = int(input("Please input a 4-digit number:"))
while True:
	m = n
	n = mys(n)
	if n == m:
		break
print("The mystery number is:", m)

randomList = []
for x in range(0, 5):
	randomList.append(random.randint(1000, 9999))
	print("The random number is", randomList[x])
	while True:
		m = randomList[x]
		randomList[x] = mys(randomList[x])
		if randomList[x] == m:
			break
	print("The mystery number is:", m)
