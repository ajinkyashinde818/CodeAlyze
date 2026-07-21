import sys
import numpy as np

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N = int(readline())
A = np.array(read().split(), np.int64)

def main(N, A):
    k = N * (N + 1) // 2
    t = A.sum() // k
    if k * t != A.sum():
        return False
    B = np.empty_like(A)
    B[1:] = A[1:] - A[:-1]
    B[0] = A[0] - A[-1]
    B -= t
    if np.any(B % N != 0):
        return False
    B //= (-N)
    return np.all(B >= 0)

print('YES' if main(N, A) else 'NO')
