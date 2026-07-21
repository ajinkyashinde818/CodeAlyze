import sys
input = sys.stdin.readline
K, N = map(int, input().split())
a = list(map(int, input().split()))
d = [0] * N
for i in range(N): d[i] = abs(a[i - 1] - a[i])
d[0] = min(d[0], K - d[0])
print(sum(d) - max(d))
