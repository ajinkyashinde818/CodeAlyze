from copy import deepcopy
n = int(input())
x = list(map(int, input().split()))
mod = 10 ** 9 + 7
c = 1
for i in range(2, n):
    c *= i
    c %= mod
c2 = deepcopy(c)
ans = 0
for i in range(n):
    ans += (x[i] - x[i - 1]) * c2
    ans %= mod
    c2 += pow(i + 1, mod - 2, mod) * c
    c2 %= mod
print(ans)
