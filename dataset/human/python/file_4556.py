def factorization(n):
    ans = 0
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            tmp = set()
            while temp%i==0:
                cnt+=1
                temp //= i
                if not cnt in tmp:
                    tmp.add(cnt)
                    cnt = 0
                    ans += 1

    if temp!=1:
        ans += 1

    if ans==0 and temp!=1:
        ans += 1

    return ans

N = int(input())
print(factorization(N))
