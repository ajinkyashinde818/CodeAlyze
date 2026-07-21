from itertools import accumulate
mod = 10 ** 9 + 7

N = int(input())
X = tuple(map(int, input().split()))
DX = [xr - xl for xl, xr in zip(X[:-1], X[1:])]

from1 = [1]
fromN = [1]
for i in range(1, N):
    from1.append(from1[-1] * i % mod)  # 1, 1*2, 1*2*3,...
    fromN.append(fromN[-1] * (N - i) % mod)  # 4, 4*3, 4*3*2, ...
fromN.reverse()

cnt = []
for a, b in zip(fromN[1:], from1[:-1]):
    cnt.append(a * b % mod)
cnt = list(accumulate(cnt))

ans = 0
for dx, c in zip(DX, cnt):
    ans = (ans + dx * c) % mod
print(ans)
