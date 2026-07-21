def factorization(n): #素因数分解のプログラム([素因数,指数]のリストのリストで出力→24→[[2, 3], [3, 1]])
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

import math
import sys
n = int(input())
ls = factorization(n)
q = 0
if n == 1:
    print(0)
    sys.exit()
for i in range(len(ls)):
    j = 1
    k = 2
    p = 0
    while True:
        if ls[i][1] >= j:
            j += k
            p += 1
            k += 1
        else:
            break
    q += p
print(q)
