import math
n = int(input())
s = list(input())
mod = 10**9 + 7

now = 0
result = 1
for i in range(2 * n):
    if s[i] == 'B':
        if now % 2 == 0:
            now += 1
        else:
            result = (result * now) % mod
            now -= 1
    else:
        if now % 2 == 0:
            result = (result * now) % mod
            now -= 1
        else:
            now += 1
if now != 0:
    result = 0
print((result * math.factorial(n)) % mod)
