import sys
import numpy as np

read = sys.stdin.read

N, *x = map(int, read().split())
mod = 10 ** 9 + 7
'''
x_(i+1)が選ばれる前にx_iが選ばれれば, x_(i+1)-x_iを加算
(N-1)!通りの中でこのような状況はsum (N-i)! i=2toN-1

x_(i+n)が選ばれる前、かつx_(i+1)からx_(i+n-1)が選ばれた後にx_iが選ばれれば, x_(i+n)-x_iを加算

'''
inv = [0] * N
for i in range(1, N):
    inv[i] = pow(i, mod - 2, mod)

for i in range(2, N):
    inv[i] = (inv[i] + inv[i - 1]) % mod

fact = 1
for i in range(1, N):
    fact *= i
    fact %= mod

x = np.array(x, np.int64)
X = x[1:] - x[:-1]
inv = np.array(inv[1:], np.int64)

answer = X * inv % mod * fact % mod
print(answer.sum() % mod)
