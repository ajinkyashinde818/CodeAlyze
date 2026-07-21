import numpy as np
N = int(input())
a = list(map(int,input().split()))
x = np.array([0]*(N))
suma = sum(a)
for i in range(1,N):
    x[i] = x[i-1] + a[i-1]
y = np.array([suma]*(N))-x
ans = list(map(abs,x-y))
print(min(ans[1:]))
