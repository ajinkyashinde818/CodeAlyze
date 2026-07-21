import copy
d,g=map(int,input().split())
pc=[]
for _ in range(d):
	x,y=map(int,input().split())
	pc.append([x,y])
pcc=copy.deepcopy(pc)
def two(x):
	p=bin(x)
	return "0"*10+p[2:]
q=[]
for i in range(2**d):
	pcc=copy.deepcopy(pc)
	ans=0
	cnt=0
	k=[]
	for j in range(d):
		if two(i)[-j-1]=="1":
			ans+=100*pc[j][0]*(j+1)+pc[j][1]
			cnt+=pc[j][0]
		else:
			k.append(j)
	p=1
	if ans<g:
		while ans<g:
			if p>len(k):
				cnt+=10**15
				break
			if pcc[k[-p]][0]<=1:
				p+=1
			if p>len(k):
				cnt+=10**15
				break
			ans+=(k[-p]+1)*100
			pcc[k[-p]][0]-=1
			cnt+=1
	q.append(cnt)
print(min(q))
