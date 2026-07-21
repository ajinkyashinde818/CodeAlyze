import math
def fact(n):
    ans = 1
    for i in range(2, n+1):
        ans*= i
    return ans
def comb(n, c):
    return fact(n)//(fact(n-c)*c)
n, k = map(int, input().split())
a = list(map(int, input().split()))
cnt=  0
i = 1
cycle = ['1']
set = {'1'}
for c in range(n):
    i = a[i-1]
    if(i in set):
        break
    else:
        cycle.append(i)
        set.add(i)

ind = cycle.index(i)
k-= ind
rcycle = cycle[ind:]
if(k <= 0):
    print(cycle[k+ind])
else:
    now = (k+1)%len(rcycle)
    print(rcycle[now-1])
