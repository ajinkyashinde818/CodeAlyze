from collections import defaultdict

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

def Fib(n):
    a, b = 0, 1
    if n == 1:
        return a
    elif n == 2:
        return b
    else:
        for i in range(n-2):
            a, b = b, a + b
        return b

N = int(input())
if(N == 1):
    print(0)
else:
    fact = factorization(N)
    l = [i for i in range(1,1000)]
    count = 0
    d = {}
    for n in fact:
        num = n[1]
        for f in l:
            num -= f
            if(num < 0):
                break
            count += 1
    print(count)
