import math

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

n = int(input())

primes = factorization(n)
cnt = 0

for i in primes:
    if primes == [[1, 1]]:
        break
    cnt += math.floor(math.sqrt(2*i[1]+1/4)-1/2)

print(cnt)
