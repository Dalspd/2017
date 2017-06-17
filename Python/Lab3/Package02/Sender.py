import socket
import datetime

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
while True:
	now = datetime.datetime.now()
	inp = input("Input your message:")
	info = now.strftime('%Y-%m-%d %H:%M:%S') + " " + inp
	s.sendto(info.encode(), ("127.0.0.1", 8888))
	if inp == 'Bye' or inp == 'bye':
		break
	del now
s.close()
