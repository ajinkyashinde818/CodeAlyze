from collections import deque

S = deque(input())
Q = int(input())

rev = False
for i in range(Q):
	query = input().split()
	if query[0] == '1':
		rev = not rev
	else:
		if (query[1] == '1' and rev == False) \
		or (query[1] == '2' and rev == True):
			S.appendleft(query[2])
		else:
			S.append(query[2])

if rev:
	S.reverse()

print("".join(S))
