from collections import deque
N=input()
a=map(int, raw_input().split())
b=map(int, raw_input().split())

S=[]
def bfs(n,start,end):
	c=[set() for i in range(51)]

	for i in range(51):
		for j in range(1,n+1):
	 		c[i].add(i%j)

	for i in range(51):
	 	c[i].add(i)

	for i in range(51):
		for j in S:
			c[i].add(i%j)

	V=[ None for i in range(51) ]

	q = deque([]) 
	V[start]=1
	q.append(start)

	while len(q)!=0:
		v=q.popleft()
		for i in c[v]:
			if i==end:
				return True
			else:
				if V[i] is None:
					V[i]=1
					q.append(i)
	else:
		return False



for i in range(50,-1,-1):
	#print i
	for x,y in zip(a,b):
		#print i,x,y,bfs(i,x,y)
		if not bfs(i,x,y):
			if i==50:
				print -1
				quit()
			else:
				S.append(i+1)


ans=0
for i in S:
	ans+=2**i
print ans
