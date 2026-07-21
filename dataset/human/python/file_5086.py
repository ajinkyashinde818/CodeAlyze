import numpy as np

N, M = map(int, raw_input().split())

possible1 = []
possibleN = []

for i in range(M):
    a, b = map(int, raw_input().split())
    if a == 1:
        possible1.append(b)

    if b == N:
        possibleN.append(a)

product = set(possible1) & set(possibleN)

if len(product) != 0:
    print "POSSIBLE"
else:
    print "IMPOSSIBLE"
