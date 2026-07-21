import sys
import numpy as np

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
 
n, k = map(int, readline().split())
a = np.int32(read().split())
 
a -= 1

b = [0]
t = 0

for i in range(n):
    t = a[t]
    b.append(t)

d = b.index(b[-1]) - 1
r = len(b) - d - 2

if k > n:
    k = (k-d) % r + d

print(b[k]+1)
