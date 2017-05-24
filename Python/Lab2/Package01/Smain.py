from Package01.Stack import Stack

s = Stack(5)
for i in range(5):
	s.pushstack(i)
s.peekstack()
for i in range(3):
	s.popstack()
	s.peekstack()
s.printAll()
