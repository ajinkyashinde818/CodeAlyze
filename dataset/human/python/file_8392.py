import sys
sys.setrecursionlimit(4100000)

k,n = map(int,input().split())
a = list(map(int,input().split()))
b = []
for v in range(n-1):
    b.append(a[v+1]-a[v])

b.append(k-a[n-1]+a[0])
anss = max(b)
ans = k - anss
print(str(ans))
