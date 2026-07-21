n, s=map(int,input().split())
q=[list(map(int, input().split())) for i in range(n)]

import numpy as np
import itertools
import pprint

bit=[0,1]

cmp=list(itertools.product(bit, repeat=n))

cp=[0]*n
qt=[0]*n
cnt=[0]*2**n

for i in range(n):
	cp[i]=100*(i+1)*q[i][0]+q[i][1]
	qt[i]=q[i][0]

cmp_cnt=np.dot(np.array(qt),np.array(cmp).T)

for i in range(2**n):
	score=np.dot(np.array(cp),np.array(cmp[i]).T)
	cnt[i]=cmp_cnt[i]
	if score<s:
		j=n-1
		while score<s and j>=0:
			if cmp[i][j]==0:
				for k in range(qt[j]):
					score+=(j+1)*100
					cnt[i]+=1
					if score>=s:
						j=0
						break
			j-=1
                
print(min(cnt))
