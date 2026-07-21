n = int(input())

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

factor = factorization(n)

ans = 0
for a in factor:
    if a[0] == 1:
        print(0)
        exit(0)
    else:
        for i in range(1,10000):
            a[1] -= i
            if a[1]>=0:
                ans += 1
            else:
                break

print(ans)
