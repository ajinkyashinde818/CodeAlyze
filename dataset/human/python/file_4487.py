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


r = 0
if n != 1:
    f = factorization(n) 
    num = []
    for a, b in f:
        for i in range(b):
            num.append(a ** (i + 1))
    num.sort()
    for c in num:
        if n < c:
            break
        else:
            if n % c == 0:
                n /= c
                r += 1

print(r)
