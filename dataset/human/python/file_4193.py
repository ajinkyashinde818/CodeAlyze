n = int(input())

if n == 1:
    print(0)
else:

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

    fact = factorization(n)

    ans = 0
    for x, y in fact:
        tmp = 1
        while True:
            if (tmp + 1) * (tmp + 2) // 2 <= y:
                tmp += 1
            else:
                break

        ans += tmp

    print(ans)
