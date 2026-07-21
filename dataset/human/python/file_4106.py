import math
n = int(input())
if n==1:
    print(0)
    quit()
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
def sigma(n):
    s=0
    for i in range(1,n+1):
         s+=i
    return s
ans = 0
for f in factorization(n):
    index = f[1]
    num=1
    while True:
        num+=1
        if index<sigma(num):
            ans+=num-1
            break
print(ans)
