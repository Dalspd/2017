import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(('127.0.0.1', 8888))
file = open('out.txt', 'w')
while True:
	data, addr = s.recvfrom(1024)
	info = (data.decode())[20:]
	if info == 'bye' or info == 'Bye':
		break
	else:
		print(data.decode(), addr[0], addr[1])
		file.write(data.decode() + " " + addr[0] + " " + str(addr[1]) + "\n")
s.close()
