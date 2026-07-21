from collections import deque
s=input()
Q=int(input())
hanten = 0
mae = deque()
ushiro = deque()
for i in range(Q):
	q=input()
	if q=="1":
		hanten ^= 1
	else:
		if q[2] == "1":
			if hanten == 0:
				mae.appendleft(q[4])
			else:
				ushiro.append(q[4])
		else:
			if hanten == 0:
				ushiro.append(q[4])
			else:
				mae.appendleft(q[4])
if hanten == 0:
	print("".join(mae) + s + "".join(ushiro))
else:
	print(("".join(mae) + s + "".join(ushiro))[::-1])
