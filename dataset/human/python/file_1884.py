import numpy as np 

n,m = map(int,input().split())
a,b=[],[]

for _ in range(n):
    a.append(list(input()))
for _ in range(m):
    b.append(list(input()))

anp=np.array(a)
bnp=np.array(b)

for ax in range(n-m+1):
    for ay in range(n-m+1):
        crnt=anp[ax:ax+m,ay:ay+m]
        if (crnt==bnp).all():
            print('Yes')
            exit()
print('No')
