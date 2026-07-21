import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

k,n = map(int, input().split())
a = list(map(int, input().split()))

diff = [a[i + 1] - a[i] for i in range(n - 1)]
diff.append(k - a[n - 1] + a[0])

ma = 0
for i in range(n):
    ma = max(ma, diff[i])

print(k - ma)
