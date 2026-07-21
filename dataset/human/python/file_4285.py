def prime(n,p):
    iteral = 0
    while n%p == 0:
        n //= p
        iteral += 1
    return iteral,n
def ok(n,target):
    if n*(n+1)//2<=target<(n+1)*(n+2)//2:return True
    else:
        return False
N = int(input())
from collections import defaultdict
d = defaultdict(int)
for i in range(2,int(N**0.5)):
    if N%i==0:
        t,N = prime(N,i)
        d[i] = t
if N != 1:
    d[N] = 1
ans = 0
for n in d:
    k = 1
    while not ok(k,d[n]):
        k += 1
    ans += k

print(ans)
