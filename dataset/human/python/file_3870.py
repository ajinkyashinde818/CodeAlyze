import math
import sys
import bisect

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
N=int(input())
if N==1:
  print(0)
  sys.exit()
L=(factorization(N))
#print(L)
L_ans = [1,3,6,10,15,21,28,36,45,55,66,78]
L_2 = [bisect.bisect(L_ans,L[i][1]) for i in range(len(L))]
#print(L_2)
print(sum(L_2))
