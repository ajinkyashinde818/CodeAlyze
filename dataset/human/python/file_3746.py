import heapq
import math
n = int(input())

element = int(math.sqrt(n))
nk = n
i = 2
p = []
while nk>1 and i <= element:
    if nk % i == 0:
        p.append(i)
        while nk % i == 0:
            nk //= i
    i += 1
if nk > 1:
    p.append(nk)
ans = 0
option = [[k, k] for k in p]
heapq.heapify(option)
while n>1 and option:
    val, p = heapq.heappop(option)
    #print(n, ans, val, option)
    if val*p <= n:
        heapq.heappush(option, [val*p, p])
    if n % val == 0:
        ans += 1
        n //= val
print(ans)
