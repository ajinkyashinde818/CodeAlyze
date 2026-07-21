from collections import deque
import sys
input=sys.stdin.readline
s=deque([input().rstrip()])
q=int(input())
rev=0
for _ in range(q):
	qw=input().split()
	if qw[0]=="1":
		rev+=1
	else:
		f=qw[1]
		c=qw[2]
		if f=="1":
			if rev%2==0:
				s.appendleft(c)
			else:
				s.append(c)
		else:
			if rev%2==0:
				s.append(c)
			else:
				s.appendleft(c)
ans=""
for x in s:
	ans+=x
if rev%2==0:
	print(ans)
else:
	print(ans[::-1])
