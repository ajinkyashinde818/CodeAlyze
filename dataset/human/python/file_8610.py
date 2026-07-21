from collections import deque

k, n = [int(i) for i in input().split()]
data = [int(i) for i in input().split()]

d = deque(data)
d.appendleft(0)
d.pop()

bet = [i-j for i, j in zip(data, d)]

bet[0] += k - data[-1]

print(k - max(bet))
