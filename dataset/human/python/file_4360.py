import math
import collections


def trial_division(n):
    factor = []
    tmp = int(math.sqrt(n)) + 1
    for num in range(2, tmp):
        while n % num == 0:
            n //= num
            if num != 1:
                factor.append(num)
    if not factor:
        return -1
    else:
        factor.append(n)
        return factor


n = int(input())
l = trial_division(n)
if n == 1:
    print(0)
    exit(0)
if l == -1:
    print(1)
    exit(0)
if l[len(l) - 1] == 1:
    l = l[:-1]
c = collections.Counter(l)

ans = 0
for k, v in c.items():
    s = 1
    for i in range(1, v):
        if i * (i + 1) <= v * 2:
            s = max(s, i)
    ans += s
print(ans)
