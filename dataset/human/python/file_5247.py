import sys
import numpy as np
input = sys.stdin.readline
N, M = [int(x) for x in input().split()]
I = []
for _ in range(M):
    I.append([int(x) for x in input().split()])
s_1 = set()
s_N = set()
for i in I:
    if i[0] == 1 and i[1] == N:
        print("POSSIBLE")
        sys.exit()
    if i[0] == 1:
        if i[1] in s_N:
            print("POSSIBLE")
            sys.exit()
        s_1.add(i[1])
    if i[1] == N:
        if i[0] in s_1:
            print("POSSIBLE")
            sys.exit()
        s_N.add(i[0])
for j in s_1:
    if j in s_N:
        print("POSSIBLE")
        sys.exit()
print("IMPOSSIBLE")
