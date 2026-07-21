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
if n == 1:
    print(0)
    exit()
factors = factorization(n)
ans = 0
for f, num in factors:
    i = 1
    while num >= i:
        num -= i
        i += 1
        ans += 1
print(ans)
