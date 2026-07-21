from sys import stdin
import math
import fractions
import heapq

k, s = [int(x) for x in stdin.readline().rstrip().split()]

cnt = 0
for x in range(k+1):
    for y in range(k+1):
        z = s - x - y
        if z >= 0 and z <= k:
            cnt += 1

print(cnt)
