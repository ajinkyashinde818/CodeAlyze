def resolve():
    n=int(input())

    def f(n):
        arr = []
        temp = n
        for i in range(2, int(-(-n ** 0.5 // 1)) + 1):
            if temp % i == 0:
                cnt = 0
                while temp % i == 0:
                    cnt += 1
                    temp //= i
                arr.append(cnt)

        if temp != 1:
            arr.append(1)

        if arr == []:
            arr.append(1)

        return arr
    if n==1:
        print(0)
    else:
        a=f(n)
        ans=0
        for i in a:
            k=1
            while i>=k:
                i-=k
                k+=1
            ans+=k-1
        print(ans)
resolve()
