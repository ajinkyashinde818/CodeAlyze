from sys import stdin
import math
import fractions
from collections import deque

INF = 10 ** 10

R, G, B, N = [int(x) for x in stdin.readline().rstrip().split()]

cnt = 0
R, G, B = sorted([R, G, B])
RN = N // R + 1
GN = N // G + 1
BN = N // B + 1

cnt = 0
for i in range(RN):
    tmpN = N - R*i
    if tmpN % G == 0:
        cnt += 1
    for j in range(GN):
        tmpN2 = tmpN - G*j
        if tmpN2 > 0 and tmpN2 % B == 0:
            cnt += 1
    

print(cnt)
