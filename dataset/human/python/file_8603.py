import math
K,N = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
for i in range(N):
    a.append(a[i] + K)
minimum = math.inf 
for i in range(N):
    minimum = min(minimum,a[i+N-1]-a[i])
print(minimum)
