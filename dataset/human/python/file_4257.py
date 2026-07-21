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
N = input()
N = int(N)
if N == 1:
    print(0)
else:    
    ans = 0
    lis = factorization(N)
    for l in lis:
        cnt = 1
        a = l[1]
        while a > 0:
            a = a - cnt
            if a >= 0:
                cnt = cnt + 1
            else:
                break
        ans = ans + cnt - 1
    print(ans)
