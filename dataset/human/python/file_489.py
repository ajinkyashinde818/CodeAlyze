import numpy as np
n = int(input())
a = list(map(int, input().split()))

mynas=0
for i in range(n):
    if a[i]<0:
        mynas += 1

a=np.array(a)
a=np.abs(a)
a=np.sort(a)
goukei=0

if mynas % 2 ==0:
    for j in range(n):
        goukei += a[j]
else:
    for k in range(n):
        goukei+=a[k]
    goukei-=a[0]*2

print(goukei)
