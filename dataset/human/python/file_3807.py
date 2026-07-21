from bisect import bisect_right
import sys

n = int(input())

if n == 1:
    print(0)
    sys.exit()

x = [1]
for i in range(2, 100):
    x.append(x[-1] + i)

l = []
tmp = n
for i in range(2, int(n**0.5)+1):
    if tmp % i == 0:
        cnt = 0
        while tmp % i == 0:
            tmp //= i
            cnt += 1
        l.append([i, cnt])
if tmp != 1:
    l.append([tmp, 1])
if l == []:
    l.append([n, 1])

res = 0
for v, c in l:
    res += bisect_right(x, c)

print(res)
