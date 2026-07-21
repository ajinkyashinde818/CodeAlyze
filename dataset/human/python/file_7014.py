from collections import deque

s = input()
q = int(input())
revflag = 1
d = deque(s)
for i in range(q):
	tfc = list(map(str, input().split()))
	if tfc[0] == '1':
		revflag *= -1
	elif tfc[1] == '1':
		if revflag > 0:
			d.appendleft(tfc[2])
		else:
			d.append(tfc[2])
	else:
		if revflag > 0:
			d.append(tfc[2])
		else:
			d.appendleft(tfc[2])
if revflag > 0:
	print(''.join(d))
else:
	print(''.join(reversed(d)))
