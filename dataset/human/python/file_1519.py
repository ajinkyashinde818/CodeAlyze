import numpy as np

n, m = map(int,input().split())
a = [input().split() for i in range(n)]
b = [input().split() for i in range(m)]

aa = np.zeros((n,n), dtype=int)
for i in range(n):
    for j in range(n):
        if a[i][0][j] == '#':
            aa[i][j] = 1

bb = np.zeros((m,m), dtype=int)
for i in range(m):
    for j in range(m):
        if b[i][0][j] == '#':
            bb[i][j] = 1

flg = False
for i in range(n-m+1):
    for j in range(n-m+1):
        aaa = aa[i:i+m,j:j+m]
        if np.all(aaa == bb):
            flg = True

print('Yes') if flg else print('No')
