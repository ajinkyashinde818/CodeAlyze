import sys
import numpy as np

stdin = sys.stdin
 
ri = lambda: int(rs())
rl = lambda: list(map(int, stdin.readline().split()))
rs = lambda: stdin.readline().rstrip()  # ignore trailing spaces

R, G, B, N = rl()
UP = 3000
A = np.zeros(UP+1, dtype=np.int32)

for r in range(UP+1):
    if r * R > UP:
        break
    A[r*R::G] += 1

answer = A[N::-B].sum()
print(answer)
#08
