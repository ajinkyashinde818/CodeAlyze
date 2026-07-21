import math
from collections import defaultdict
from bisect import bisect_right

def trial_division(n):
    factor = defaultdict(int)
    tmp = int(math.sqrt(n)) + 1
    for num in range(2, tmp):
        while n % num == 0:
            n //= num
            factor[num] += 1
    factor[n] += 1
    return factor


n = int(input())
r = trial_division(n)
check = [i for i in range(1, 101)]
for i in range(len(check)-1):
    check[i+1] += check[i]

ans = 0
for k, v in r.items():
    if k == 1:
        continue

    ans += bisect_right(check, v)

print(ans)
