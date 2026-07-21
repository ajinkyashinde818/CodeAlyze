n = int(input())
if n == 1:
    print(0)
    exit()
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

A = factorization(n)

ans = 0
for a in A:
    cnt = 1
    b = a[1]
    while (b-cnt) >= 0:
        b -= cnt
        cnt += 1
        ans += 1

print(ans)
