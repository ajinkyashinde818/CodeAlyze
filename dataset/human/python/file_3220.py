def furui(n):
    if n < 2:
        return []
    plist = [1 for i in range(n)]
    plist[0] = plist[1] = 0
    for i in range(2, n):
        if plist[i]:
            for j in range(i*2, n, i):
                plist[j] = 0
    ret = []
    for i in range(n):
        if plist[i] != 0:
            ret.append(i)
    return ret


primes = furui(1000000)
count = 0
N = int(input())


if N == 1:
    print(0)
else:
    # 素因数分解する
    factors = []
    for p in primes:
        if N % p == 0:
            e = 1
            while N % (p ** (e+1)) == 0:
                e += 1
            factors.append((p, e))
            N /= p ** e
    if N != 1:
        # 10^6より大きい素数
        factors.append((N, 1))
    # print(factors)

    # 数える
    count = 0
    for p, e in factors:
        s = 0
        for i in range(1, e+1):
            s += i
            if s <= e:
                # print(p ** i)
                count += 1
            else:
                break
    print(count)
