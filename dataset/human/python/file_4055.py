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
f = factorization(n)
#print(f)
ans = 0
for a,b in f:
    if a > 1:
        i = 1
        t = 0
        while True:
            if b - i >= 0:
                t += 1
                b -= i
                i += 1
            else:
                break

        #print(a,t)
        ans += t

print(ans)
