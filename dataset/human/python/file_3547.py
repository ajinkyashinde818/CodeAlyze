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

F = factorization(N)
import math
f = []
if F[0][0] != 1:
  for i in range(len(F)):
    f.append(int((math.sqrt(8*F[i][1]+1) - 1)/2))

print(sum(f))
