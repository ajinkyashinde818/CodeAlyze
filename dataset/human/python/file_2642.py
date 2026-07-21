li = lambda: list(map(int,input().split()))

d,g = li()
g //= 100
num,comp = [], []
for _ in range(d):
    a,b = li()
    num.append(a)
    comp.append(b//100)

from itertools import product
mul = product((0, 1), repeat=d)

ans = float('inf')
for m in mul:
    pt = sum(m[i]*comp[i] for i in range(d)) + sum(m[i]*(i+1)*num[i] for i in range(d))
    n = sum(m[i]*num[i] for i in range(d))
    if pt < g:
        if not all(m):
            i = [i for i,j in enumerate(m) if j==0][-1]
        else:
            continue
        if pt + (i+1)*(num[i]-1) < g:
            continue
        n += -((pt-g)//(i+1))
    ans = min(ans,n)
print(ans)
