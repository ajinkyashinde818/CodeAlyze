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

def saidai(n):
    ans = int(math.sqrt(2 * n)) - 1
    while 2 * n >= (ans + 1) * (ans + 2):
        ans += 1
    return(ans)

N = int(input())
fac = factorization(N)
index = []
for i in fac:
    index.append(i[1])
ans = 0
for i in index:
    ans += saidai(i)
if N == 1:
    print(0)
else:
    print(ans)
