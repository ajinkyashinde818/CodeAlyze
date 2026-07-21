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

N = int(input())

ans = 0
s = factorization(N)

if s[0][0] != 1:
    for i in range(len(s)):
        cnt = 1
        rest = s[i][1]
        while True:
            if cnt <= rest:
                N = N//(s[i][0]**cnt)
                rest -= cnt
                cnt += 1
                ans += 1
            else:
                break
    print(ans)
else:
    print(0)
