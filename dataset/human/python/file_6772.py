from collections import deque

s_list = list(input())
d = deque(s_list)
q = int(input())
reverse = False

for _ in range(q):
	query= input().split()
	if int(query[0]) == 1:
		if reverse: reverse = False
		else: reverse = True
	elif int(query[0]) == 2:
		if int(query[1]) == 1:
			if reverse:
				d.append(query[2])
			else:
				d.appendleft(query[2])
		elif int(query[1]) == 2:
			if reverse:
				d.appendleft(query[2])
			else:	
				d.append(query[2])


if reverse:
	d.reverse()
for s in d:
  print(s, end ="")
