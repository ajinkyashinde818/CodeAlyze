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
n = int(input())
f = [None for _ in range(40)]
f[1] = 1
for i in range(2, 40):
    if (f[i-1]+1)*(f[i-1]+2) == 2*i:
        f[i] = f[i-1]+1
    else:
        f[i] = f[i-1]   

if n==1:
    print(0)
else:
    arr = factorization(n)
    for a,b in arr:
        ans += f[b]
    print(ans)
