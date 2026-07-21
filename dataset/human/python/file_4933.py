import sys
import numpy as np

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

def cumprod(arr, MOD):
    L = len(arr); Lsq = int(L**.5+1)
    arr = np.resize(arr, Lsq**2).reshape(Lsq, Lsq)
    for n in range(1, Lsq):
        arr[:, n] *= arr[:, n-1]; arr[:, n] %= MOD
    for n in range(1, Lsq):
        arr[n] *= arr[n-1, -1]; arr[n] %= MOD
    return arr.ravel()[:L]

def make_fact(U, MOD):
    x = np.arange(U, dtype=np.int64); x[0] = 1
    fact = cumprod(x, MOD)
    x = np.arange(U, 0, -1, dtype=np.int64); x[0] = pow(int(fact[-1]), MOD-2, MOD)
    fact_inv = cumprod(x, MOD)[::-1]
    return fact, fact_inv

MOD = 10 ** 9 + 7
U = 10 ** 5 + 10 # 階乗テーブルの上限
fact, fact_inv = make_fact(U, MOD)
N = ir()
X = np.array(lr())

inv = np.zeros(U, np.int64)
inv[1:] = fact_inv[1:] * fact[:-1] % MOD
coef = inv[1:N].cumsum() % MOD
answer = (np.diff(X) * coef % MOD).sum() % MOD
answer *= fact[N-1]
print(answer % MOD)
# 35
