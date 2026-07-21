from collections import deque

S = deque(input())
queryNum = input()
flip = False
for i in range(int(queryNum)):
	order = input()
	if order == '1':
		if flip:
			flip = False
		else:
			flip = True
	else:
		if order[2] == '1':
			if not flip:
				S.appendleft(order[4])
			elif flip:
				S.append(order[4])
		else:
			if not flip:
				S.append(order[4])
			elif flip:
				S.appendleft(order[4])
S = ''.join(S)
if flip:
	print(S[::-1])
else: 
	print(S)
