N = int(input())


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


ans = 0
prime = factorization(N)
if N == 1:
    print(0)
    exit()
for li in prime:
    check = li[1]
    i = 1
    while check > 0:
        if check >= i:
            ans += 1
        check -= i
        i += 1
print(ans)
