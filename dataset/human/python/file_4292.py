import math
def fac(n):
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

n = int(input())
if n==1:
    print(0)
elif is_prime(n):
    print(1)
else:
    cnt = 0
    P = fac(n)
    for p,_ in P:
        c = 1
        while n%pow(p,c)==0:
            n /= pow(p,c)
            cnt += 1
            c += 1
    print(cnt)
