import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
import numpy as np

N = int(readline())
A = [int(x) for x in readline().rstrip().split()]

B = []
cnt = 0
for i in A:
    if i < 0:
        cnt += 1
    B.append(abs(i))

if cnt % 2 == 0:
    print(sum(B))
else:
    print(sum(B) - 2 * min(B))
