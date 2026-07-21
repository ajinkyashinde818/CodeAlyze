from itertools import combinations

D,G=map(int,input().split())
p=[0]*D
c=[0]*D
for i in range(D):
	p[i],c[i]=map(int,input().split())


ans=100*10

for i in range(0,D+1):
	for v in combinations(range(D), i):
		t=0
		s=0
		for j in v:
			t+=p[j]
			s+=p[j]*(j+1)*100 + c[j]
		
		if s<G:
			for j in range(D)[::-1]:
				if j in v:
					pass
				else:
					k=(G-s)//((j+1)*100)
					t+=min(p[j]-1,k)
					s+=min(p[j]-1,k)*(j+1)*100
					
					if s>=G:break
		
		if s>=G:
			ans=min(ans,t)
		
print(ans)
