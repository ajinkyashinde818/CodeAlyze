import math

N, K, S = map(int, input().split())

ma = N * (N + 1) / 2

k = 1
if S == 10 ** 9:
    k = -1

li = [S for i in range(K)] + [S+k for i in range(N-K)]

for i in range(N-1):
    print(li[i], end=" ")

print(li[N-1])
