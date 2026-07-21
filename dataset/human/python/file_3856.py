from math import sqrt
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
 
if N == 1:
    ans = 0
else:
    A = factorization(N)
    B = []
    for a in A:
        B.append(a[1])
        ans = 0
    for b in B:
        n = int((-1 + sqrt(8*b + 1)) / 2)
        ans += n
print(ans)
