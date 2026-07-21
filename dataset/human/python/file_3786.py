def factorization(n):
    ans = 0
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            ch_point = 1
            while temp%i==0:
                cnt+=1
                if cnt == ch_point:
                    cnt = 0
                    ans += 1
                    ch_point += 1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])
        ans += 1

    if arr==[]:
        arr.append([n, 1])
        ans += 1

    return ans

N = int(input())
if N == 1:
    print(0)
    exit();


print(factorization(N))
