import sys
input = sys.stdin.readline
R, G, B, N = map(int, input().split())
ans = 0

for r in range(N + 1):
  for g in range(N + 1):
    if ((N - r*R - g*G) % B == 0 and (N - r*R - g*G) / B >= 0):
      ans += 1

print(ans)
