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

#超えない最大の三角数
tmp = 0
ls = [0]
for i in range(1,41):
    tmp += i
    ls += [i]*(i+1)

#print(ls[:10])

N = int(input())
if N == 1:
    print(0)
else:
    fac = factorization(N)
    ans = 0
    for p in fac:
        ans += ls[p[1]]
        #print(p)
    print(ans)
