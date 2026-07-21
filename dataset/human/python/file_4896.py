import sys
read = sys.stdin.buffer.read

n, *X = map(int, read().split())
mod = 10**9 + 7
last = X[-1]
X = [last - i for i in X[:-1]]
a, left = 1, [1]
for i in range(1, n - 1):
    a *= i  # メモリ
    a %= mod  # メモリ
    left.append(a)
b, right = 1, [1]
for i in range(n - 1, 1, -1):
    b *= i  # メモリ
    b %= mod  # メモリ
    right.append(b)
right.reverse()
flst = [(i * j % mod) % mod for i, j in zip(left, right)]
s = sum(i * j % mod for i, j in zip(X, flst))
print(s % mod)
