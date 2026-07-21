import sys
input = sys.stdin.readline

k, n = map(int, input().split())
a = list(map(int, input().split()))
a.append(k)
a[n] += a[0]
memo = [0] * n
for i in range(n):
    memo[i] = a[i + 1] - a[i]
print(sum(memo) - max(memo))
