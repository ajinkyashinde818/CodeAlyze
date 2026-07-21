from collections import defaultdict
d = defaultdict(int)
import math
def trial_division(n):
    a = [1]
    for i in range(2,int(math.sqrt(n)) + 1):
        while n % i == 0:
            n //= i
            a.append(i)
    a.append(n)
    return a
def calc(n):
    res = 0
    cnt = 1
    while True:
        if n - cnt < 0:
            return res
        n -= cnt
        res += 1
        cnt += 1
N = int(input())
for i in trial_division(N):
    if i != 1:
        d[i] += 1
ans = 0
for i in d.values():
    ans += calc(i)
print(ans)
