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
            arr.append([i, cnt])
    if temp!=1:
        arr.append([temp, 1])
    if arr==[]:
        arr.append([n, 1])
    return arr
def is_prime(n):
    if n == 1: return False
    for k in range(2, int(math.sqrt(n)) + 1):
        if n % k == 0:
            return False
    return True
if is_prime(N):
    print(1)
elif N == 1:
    print(0)
else:
    insu = factorization(N)
    ans = 0
    for i,j in insu:
        p = 1
        while True:
            j -= p
            if j >= 0:
                N = N // (i**p)
                ans += 1
            else:
                break
            p += 1
    print(ans)
