import sys
input = sys.stdin.readline

k,n = map(int,input().split())
a = list(map(int,input().split()))

ma = 0

for i in range(1,n):
    if a[i]-a[i-1] > ma:
        ma = a[i]-a[i-1]
if a[0]+k-a[-1] > ma:
    ma = a[0] + k - a[-1]
print(k-ma)
