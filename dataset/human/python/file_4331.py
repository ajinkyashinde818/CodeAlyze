from math import sqrt
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

def max(num):
    k = int(sqrt(2*num))
    for i in range(k):
        if (k-i)*(k-i+1)<=2*num:
            return k-i
    return

n = int(input())

if n == 1:
    print(0)
    exit()

li = factorization(n)

ans = 0
for i in li:
     ans +=max(i)
print(ans)
