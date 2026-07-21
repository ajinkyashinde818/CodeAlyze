import sys
import collections
sys.setrecursionlimit(4100000)

n = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
c = [int(i) for i in input().split()]

ans = sum(b)
for i in range(1,len(a)):
    if a[i] - a[i-1] == 1:
        ans += c[a[i]-2]
print(ans)
