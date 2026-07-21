from collections import deque

s = deque(input())
n = int(input())
status = True

for i in range(n):
	com = input().split()
	if com[0] == '1':
		status = not status
	elif int(com[1])+status == 2:
		s.appendleft(com[2])
	else:
		s.append(com[2])
        
if not status:
	s.reverse()
print("".join(s))
