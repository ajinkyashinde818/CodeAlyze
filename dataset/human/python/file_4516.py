from math import gcd
def prime_factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr.append([i,cnt])
    if temp != 1:
        arr.append([temp,1])
    if arr == []:
        arr.append([n,1])
    return arr
n = int(input())
if n == 1:
    print(0)
    exit()
l = prime_factorization(n)
cnt = 0
for i in l:
    for j in range(1,i[1]+1):
        if n >= i[0]**j and n % i[0]**j == 0:
            n//=i[0]**j
            cnt+= 1
print(cnt)
