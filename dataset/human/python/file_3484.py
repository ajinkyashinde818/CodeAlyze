N = int(input())
num = []
import collections
for i in range(2,int(N**0.5)+1):
    while N%i==0:
        num.append(i)
        N //= i
if N != 1:
    num.append(N)
A = collections.Counter(num)
lis = []
num = 0
for i in range(1,10):
    num += i
    lis.append(num)
from bisect import bisect_left,bisect_right
ans = 0
num = 0
for v in A.values():
    num = bisect_right(lis,v)
    ans += num
print(ans)
