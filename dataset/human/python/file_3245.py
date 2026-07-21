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

ans = 0

if N == 1:
    print(0)
else:
    t = factorization(N)
    for i in t:
        t_ = i[1]
        now = 1
        while True:
            if now > t_:
                break
            ans += 1
            t_ -= now
            now += 1
    print(ans)
