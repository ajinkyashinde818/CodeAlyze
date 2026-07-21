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

def solve():
    if N == 1:
        print(0)
        return 0
    
    ans = 0
    lst = factorization(N)
    for ps in lst:
        es = ps[1]

        tmp = 1
        while es >= tmp:
            es -= tmp
            ans += 1
            tmp += 1
    
    print(ans)
    return 0




solve()
