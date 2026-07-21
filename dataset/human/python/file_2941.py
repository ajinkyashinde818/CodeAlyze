def resolve():
    from collections import defaultdict
    import bisect
    def factorization(n):
        dic = defaultdict(int)
        temp = n
        for i in range(2, int(-(-n ** 0.5 // 1)) + 1):
            if temp % i == 0:
                cnt = 0
                while temp % i == 0:
                    cnt += 1
                    temp //= i
                dic[i] = cnt

        if temp != 1:
            dic[temp] = 1
        if not dic:
            dic[n] = 1

        return dic
    n = int(input())
    a = factorization(n)
    total = []
    sums = 0
    for i in range(1,100):
        sums += i
        total.append(sums)
    ans = 0
    for i in a.keys():
        test = a[i]
        ans += bisect.bisect_right(total, test)
    if n == 1:
        print(0)
    else:
        print(ans)
resolve()
