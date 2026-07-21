def solve(n):
    l = []
    k = int(n**0.5)
    i = 2
    tmp = 0
    while i <= n and i <= k:
        if n % i == 0:
            n = n // i
            tmp += 1
        else:
            if tmp != 0:
                l.append(tmp)
                tmp = 0
            i += 1
    if n == 1:
        l.append(tmp)
    else:
        l.append(1)
    res = 0
    for z in l:
        i = 1
        z -= i
        while z >= 0:
            res += 1
            i += 1
            z -= i
    return res





if __name__ == '__main__':
    n = int(input())
    print(solve(n))
