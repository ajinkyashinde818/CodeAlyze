import numpy as np
N = int(input())

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
  
def z(p):
    n = (-1+np.sqrt(1+8*p))/2
    return int(n)
arr = factorization(N)
if N == 1:
    print(0)
else:
    print(np.sum([z(a[-1]) for a in arr]))
