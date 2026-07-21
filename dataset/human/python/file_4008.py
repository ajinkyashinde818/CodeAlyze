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



fac = factorization(n)
ans = 0
if n == 1:
    print(0)
else:
    for i in fac:
        tem = 1
        while tem*(tem+1)//2 < i[1]:
            if i[1] >= (tem+1)*(tem+2)//2:
                tem += 1
            else:
                break
        ans += tem

    print(ans)
