from Package03.Set import Set

a = [1, 2, 3, 3, 2, 4, 5]
s = Set(a)
s.printAll()
s.addElement(1)
s.addElement(6)
s.printAll()
print(s.isMember(12))
b = [2, 4, 7]
_s = Set(b)
_s.printAll()
print(s.intersection(_s))
print(s.union(_s))
print(s.subtract(_s))
