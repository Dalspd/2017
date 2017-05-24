from Package02.Queue import Queue

q = Queue(10)
for i in range(8):
	q.enqueue(i)
q.printAll()
q.getfile("in.txt")
q.printAll()
q.putfile("out.txt")
