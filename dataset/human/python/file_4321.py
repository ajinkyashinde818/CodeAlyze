import sys
N = int(input())
if N == 1:
    print(0)
    sys.exit()
    
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

A = factorization(N)
c = 0
for i in range(len(A)):
    j = 2
    while True:
        f = j * (j - 1) / 2
        if A[i][1] < f:
            c += j - 2
            break
        j += 1
print(c)
