import sys
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))
cs = [0] * (N + 1)
for i in range(N): cs[i + 1] = cs[i] + a[i]
res = float("inf")
for i in range(1, N):
  res = min(res, abs(cs[i] - (cs[-1] - cs[i])))
print(res)
