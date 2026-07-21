import numpy as np
M = 10**9+7
N = int(input())
X = np.array(list(map(int,input().split())),dtype='int64')

D = X[1:]-X[:N-1]

ans = 0
s = 0
nn = 1
for n in range(1,N):
    nn *= n
    nn %= M

for i,d in enumerate(D):
    s = (s + pow((i+1),M-2,M))%M
    ns = (nn*s) % M
    ans = (ans + ns*d %M ) % M

print(ans)
