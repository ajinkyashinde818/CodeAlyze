import math
from collections import defaultdict
N = int(input())
d = defaultdict(int)
tmp = N
for i in range(2, int(math.sqrt(N))+1):
    while tmp % i == 0:
        d[i] += 1
        tmp /= i

if tmp > 1:
    d[tmp] += 1
ans = 0
for key, value in d.items():
    i = value
    j = 1
    while value >= j:
       ans += 1
       value -= j
       j += 1
print(ans)
