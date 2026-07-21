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
total = 0
if n == 1:
    pass
else:
    for i in factorization(n):
        t = 1
        while 1:
            if i[1]-t < 0:
                break
            else:
                total += 1
                i[1] -= t
                t += 1
print(total)
