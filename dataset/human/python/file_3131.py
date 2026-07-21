import math
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
            arr.append(cnt)

    if temp!=1:
        arr.append(1)

    if arr==[]:
        arr.append(1)

    return arr
A = factorization(N)
if N == 1:
    print(0)
else:
    for i in range(len(A)):
        if A[i] == 1:
            A[i] = 1
        else:
            s = (-1+int(math.sqrt(1+8*A[i])))/2
            A[i] = int(s)
    print(int(sum(A)))
