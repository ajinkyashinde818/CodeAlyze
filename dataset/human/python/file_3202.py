import sys
from bisect import bisect_right

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

N = int(input())

if N == 1:
    print(0)
    sys.exit()

L = factorization(N)
A = [i for i in range(1,101)]
for i in range(99):
    A[i+1] += A[i]

ans = 0
for _, l in L:
    ans += bisect_right(A,l)
print(ans)
