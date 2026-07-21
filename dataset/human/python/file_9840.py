import sys
from collections import deque
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

n, k, *a = map(int, read().split())

l = [0] * (n + 1)

q = deque([])
i = 1
while True:
    q.append(i)
    l[i] += 1
    if l[i] == 2:
        left = q.index(i)
        right = len(q)-2
        break
    i = a[i - 1]

length = right - left + 1

if k > left:
    b = k - left
    k = b % length
    print(q[left+k])
else:
    print(q[k])
