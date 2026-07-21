import numpy as np 
from sys import stdin, setrecursionlimit
 

N,K = map(int,input().split())
A = list(map(int,input().split()))

t = 1
tpass = [1]
k = 0
j = 1
temp3 = [0]*N
for i in range(N):
    temp = A[t-1] 
    if i == K-1:
        print(temp)
        exit()
    if temp3[temp-1] != 0 :
        idx = tpass.index(temp)
        l = len(tpass)
        j = -1
        break
    else:
        
        t = temp
        temp3[t-1] = 1
        tpass.append(temp)
        k += 1

try:
    a = K - k
    loop = l - idx
    b = a % loop 
    temp2 = tpass[idx:]
    ans = temp2[b-1]
    print(ans)
except:
    pass
