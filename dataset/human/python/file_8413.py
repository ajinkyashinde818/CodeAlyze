import sys

n, k = map(int, input().split())
a = list(map(int, sys.stdin.readline().split()))
ans = a[k-1] - a[0]
for i in range(1, k-1):
    if ans > n - (a[i+1] - a[i]):
        ans =  n - (a[i+1] - a[i])
print(ans)
