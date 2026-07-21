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

prime = factorization(n)

ans = 0


for i in range(len(prime)):
    s = 0
    for j in range(1, prime[i][1]+1):
        if j*(j+1)/2 <= prime[i][1]:
            s = max(s, j)
    ans += s

print(ans)
