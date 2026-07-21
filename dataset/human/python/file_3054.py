import sys
from bisect import bisect_left, bisect_right
N=int(sys.stdin.readline().strip())

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr

F=factorization(N)

L=[1]
for i in range(2,51):
    L.append(L[-1]+i)

ans=0
for x,y in F:
    if x==1: continue
    ans+=bisect_right(L,y)
print ans
