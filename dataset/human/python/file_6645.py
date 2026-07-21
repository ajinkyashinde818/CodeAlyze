from collections import deque

s=input()
s=deque(s)
q=int(input())
ans=''
flg=0
for _ in range(q):
	query=list(map(str,input().split()))
	if query[0]=='1':
		flg=1-flg
	else:
		if flg:
			if query[1]=='1':
				s.append(query[2])
			else:
				s.appendleft(query[2])
		else:
			if query[1]=='1':
				s.appendleft(query[2])
			else:
				s.append(query[2])
if flg:
	t=[]
	for i in range(len(s)):
		t.append(s.pop())
	print(''.join(t))
else:
    print(''.join(s))
