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
bunkai = factorization(n)
ans = 0
for i in bunkai:
    a = i[1]
    b = 1
    cnt = 0
    while a > 0:
        a -= b
        b += 1
        if a >= 0:
            cnt += 1
        else:
            pass
    ans += cnt
if n == 1:
    print(0)
else:
    print(ans)
