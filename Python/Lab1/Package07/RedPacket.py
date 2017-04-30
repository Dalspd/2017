from random import random


def money(amount, people):
	moneyList = []
	for x in range(0, people - 1):
		a = round(amount * random(), 2)
		moneyList.append(a)
		amount -= a
	moneyList.append(round(amount, 2))
	return moneyList


amo = float(input("Please input amount:"))
peo = int(input("Numbers of people:"))
for x in range(0, 10):
	tmp = money(amo, peo)
	print(tmp)
