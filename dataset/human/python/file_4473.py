from collections import Counter
import math

N = int(input())
c = Counter()

for i in range(2, math.ceil(math.sqrt(N)+1)+1):
    while N%i == 0:
        c.update([i])
        N = N // i
if N!=1: c.update([N])
            
def R(n):
    ret = 0
    for i in range(1, n+1):
        if n>=i:
            ret += 1
            n -= i
        else:
            break
    return ret
 
ans = 0
for n in c:
    ans += R(c[n])
print(ans)
