'''insert(...) method of builtins.list instance
    L.insert(index, object) -- insert object before index

append(...) method of builtins.list instance
    L.append(object) -> None -- append object to end'''
from time import clock

a = b = []
t0 = clock()
for x in range(1, 50001):
	a.insert(1, x)
time_a = clock() - t0
print("Using insert() time:", time_a)

t0 = clock()
for x in range(50000, 0, -1):
	b.append(x)
time_b = clock() - t0
print("Using append() time:", time_b)

if time_a > time_b:
	print("append() is faster")
elif time_a < time_b:
	print("insert() is faster")
else:
	print("Two function runs at a same speed")
