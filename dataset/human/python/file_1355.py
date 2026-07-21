n = int(input())
l = list(map(int, input().split()))

total = sum(l)

from itertools import accumulate
x = list(accumulate(l))

y = []
for i in range(n-1):
    y += [abs(total - x[i] - x[i])]

print(min(y))
