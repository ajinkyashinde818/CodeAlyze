import numpy as np
N = int(input())

def factorization(n):
    if n == 1:
        return []

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

Arr = factorization(N)

comp = []

for i in range(40):
    comp.append((i + 1) * (i + 2) / 2)

cn = np.array(comp)

Sum = 0

for arr in Arr:
    Sum += np.count_nonzero(arr[1] >= cn)
    
print(Sum)
