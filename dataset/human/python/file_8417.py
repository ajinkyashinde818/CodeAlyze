def inputs(): return [int(x) for x in input().split()]
from collections import defaultdict
k,n = inputs()
a = inputs()
ans = min(a[-1]-a[0],k-(a[1]-a[0]))
for i in range(n-1):
    if i!=0:
        ans = min(ans,min(k-abs(a[i+1]-a[i]),k-abs(a[i-1]-a[i])))
    #print(ans,i)
print(ans)
