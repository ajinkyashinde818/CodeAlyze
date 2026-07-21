from collections import deque
k,n = map(int, input().split())
a = list(map(int, input().split()))

mx = 0 
for i in range(n):
    if i == n-1:
        if mx < (k - a[n-1])+a[0]:
            mx=k-a[n-1]+a[0]
    else:
        if mx < a[i+1]-a[i]:
            mx = a[i+1] -a[i]
print(k-mx)
