import sys
import math
def input():
    return sys.stdin.readline()[:-1]

n = int(input())
def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append(cnt)

    if temp!=1:
        arr.append(1)

    if arr==[]:
        arr.append(1)
    return arr

li = factorization(n)
if n==1:
    print(0)
else:
    cnt = 0
    for x in li:
        cnt += math.floor((math.sqrt(1+8*x)-1)/2)
    print(cnt)
