from collections import deque
k, n = map(int, input().split())
a = list(map(int, input().split()))

d = deque()
for i in range(n-1):
    d.append(a[i+1] - a[i])

d.append(a[0] + k - a[-1])

print(k - max(d))
