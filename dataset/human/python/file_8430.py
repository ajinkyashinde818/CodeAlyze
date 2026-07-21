def sep():
    return map(int,input().strip().split(" "))
def lis():
    return list(sep())
import sys
sys.setrecursionlimit(10**6)

c,n=sep()
ar=lis()
ar.sort()
m=-10
for i in range(n):
    t=min(abs(ar[i]-ar[((i-1) + n)%n]),c-abs(ar[i]-ar[((i-1) + n)%n]))
    #print(t)
    if t>m:
        m=t
print(c-m)
