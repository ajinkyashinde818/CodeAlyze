import sys
from collections import deque
S=[input()]
S=deque(S)
Q=int(sys.stdin.readline())
flag=0
for i in range(Q):
	qu=tuple(input().split())
	if qu[0]=='1':
		if flag==0:
			flag+=1
		else:
			flag=0
	else:
		if qu[1]=='1' and flag==0:
			S.appendleft(qu[2])
		elif qu[1]=='1' and flag==1:
			S.append(qu[2])
		elif qu[1]=='2' and flag==0:
			S.append(qu[2])
		elif qu[1]=='2' and flag==1:
			S.appendleft(qu[2])
if flag==1:
	S=''.join(S)
	S=S[::-1]
	print(S)
	exit()
print(''.join(S))
