def factorize(n):
    """
    素因数はたかだか n**0.5 以下
    :return: e.g. factorize(24) -> {2: 3, 3: 1} (24 = 2**3 * 3**1)
    """
    res = {}
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp % i == 0:
            res[i] = 0
            while temp % i ==0:
                res[i] += 1
                temp //= i

    if temp != 1:
        res[temp] = 1

    if len(res) == 0:
        res[n] = 1

    return res

def factorize_exp(n):
    """
    Return only exponents of factorization.
    :return: e.g. factorize(24) -> [3, 1] (24 = 2**3 * 3**1)
    """
    res = []
    temp = n

    if n == 1:
        # 1 は素数ではない
        return res

    for i in range(2, int(-(-n**0.5//1))+1):
        if temp % i == 0:
            cnt = 0
            while temp % i ==0:
                cnt += 1
                temp //= i
            res.append(cnt)
    if temp != 1:
        res.append(1)

    if len(res) == 0:
        res.append(1)

    return res


n = int(input())
factors = factorize_exp(n)
cnt = 0

for i in factors:
    rem = i
    j = 1
    while rem >= j:
        rem -= j
        cnt += 1
        j += 1

print(cnt)
