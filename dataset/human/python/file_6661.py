from collections import deque

S = deque(input())
Q = int(input())
N = len(S)

flag = 0
for i in range(Q):
	q = list(map(str, input().split()))
	if q[0] == '1':
		flag = 1 - flag
	else:
		if (q[1] == '1' and flag == 1) or (q[1] == '2' and flag == 0):
			S.append(q[2])
		else:
			S.appendleft(q[2])
if flag == 1:
	S.reverse()
ans = ''.join(S)
print(ans)
