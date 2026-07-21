import sys
input = sys.stdin.readline
N, K = map(int, input().split())
a = list(map(int, input().split()))

dbl = [[0] * 61 for _ in range(N)]
for i in range(N): dbl[i][0] = a[i] - 1

for k in range(60):
  for i in range(N):
    x = dbl[i][k]
    dbl[i][k + 1] = dbl[x][k]

x = 0
while K:
  x = dbl[x][K.bit_length() - 1]
  K -= 1 << (K.bit_length() - 1)
print(x + 1)
