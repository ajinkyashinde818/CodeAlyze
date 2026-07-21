import sys

import numpy as np
import itertools

N, M = list(map(int, sys.stdin.readline().split()))
A = np.array([list(sys.stdin.readline().rstrip()) for _ in range(N)]) == "#"
B = np.array([list(sys.stdin.readline().rstrip()) for _ in range(M)]) == "#"

ok = False
for i, j in itertools.product(range(len(A) - len(B) + 1), repeat=2):
    ok |= (A[i: i + len(B), j: j + len(B)] == B).all()

if ok:
    print("Yes")
else:
    print("No")
