import itertools
D,G=map(int,input().split())
l=sorted([[(i+1)*100]+list(map(int,input().split())) for i in range(D)],key=lambda x:x[0]*x[1]+x[2])[::-1]
comb=[set(x) for i in range(D+1) for x in itertools.combinations(range(D),r=i)]
setD=set(range(D))
ans=1000
for c in comb:
	res=0
	cnt=0
	if len(setD-c)>0:min_rest=min(setD-c)
	else:min_rest=None
	for i in c:
		res+=l[i][0]*l[i][1]+l[i][2]
		cnt+=l[i][1]
	if res>=G:ans=min(ans,cnt)
	elif res<G and min_rest != None and (G-res-1)//l[min_rest][2]<l[min_rest][1]:
		cnt+=(G-res-1)//l[min_rest][0]+1
		ans=min(ans,cnt)
print(ans)
