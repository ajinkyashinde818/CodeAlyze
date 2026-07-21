from itertools import accumulate
N = int(input())
a = list(map(int,input().split()))
acc = list(accumulate(a))
m = float("inf")
for i in range(0, N-1):
    x = acc[i]
    y = acc[-1]-x
    m = min(abs(x-y), m)
print(m)
