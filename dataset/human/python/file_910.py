from itertools import accumulate

N, C, *XV = map(int, open(0).read().split())

X = XV[::2]
V = XV[1::2]

A = [0] + list(accumulate(V))

ans = m0 = m1 = 0
for i in reversed(range(N)):
    a = A[i + 1] - X[i]
    ans = max(ans, a + m0, a - X[i] + m1)

    c = C - X[i]
    m = A[N] - A[i] - c
    m0 = max(m0, m - c)
    m1 = max(m1, m)

print(max(ans, m1))
