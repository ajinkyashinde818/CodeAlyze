n,m=map(int,input().split())
from collections import Counter
cc=Counter()
for _ in range(m):
    a,b=map(lambda x:int(x)-1, input().split())
    cc[(a,b)]=1
    cc[(b,a)]=1
for i in range(1,n-1):
    if cc[(0,i)] and cc[(i,n-1)]:
        print('POSSIBLE')
        import sys
        sys.exit()
print('IMPOSSIBLE')
