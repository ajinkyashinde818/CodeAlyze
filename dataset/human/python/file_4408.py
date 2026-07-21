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
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr

n = int(input())
fac = factorization(n)
s = 0
for i in fac:
    if i[0] != 1:
        s += (-1+sqrt(1+4*i[1]*2))//2
print(int(s))
