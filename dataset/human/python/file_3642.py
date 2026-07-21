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

N = int(input())
fac = []
fac = factorization(N)

#print(fac)

def sankaku(x):
    ans = 0
    for i in range(int(2*math.sqrt(x))):
        if i*(i+1)//2 < x:
            ans += 1
        else:
            pass
    return ans

def truesan(x):
    return sankaku(x+1)-1

#print(truesan(N))

a = 0
for i in range(len(fac)):
    a += truesan(fac[i][1])

print(a if N != 1 else 0)
