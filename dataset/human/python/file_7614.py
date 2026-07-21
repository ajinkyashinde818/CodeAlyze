from collections import deque
D=deque(input().rstrip())
Q=int(input())
count=0
for _ in range(Q):
	Y=list(input().split())
	if Y[0]=="1":
		count=(count+1)%2
	else:
		if Y[1]=="1":
			if count==0:
				D.appendleft(Y[2])
			else:
				D.append(Y[2])
		else:
			if count==0:
				D.append(Y[2])
			else:
				D.appendleft(Y[2])
D=list(D)
if count==0:
	print("".join(D))
else:
	D.reverse()
	print("".join(D))
