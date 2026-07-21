def p_facto(n):
    ret = []
    nc = n
    for i in range(2, nc):
        if i*i > nc:
            break
        if n % i == 0:
            ex = 0
            while n % i == 0:
                ex += 1
                n //= i
            ret.append([i, ex])
    if n != 1:
        ret.append([n, 1])
    return ret


def main(N):
    ans = 0
    for p, e in pf:
        ex = 1
        while True:
            z = p**ex
            if N % z == 0:
                ans += 1
                N //= z
            else:
                break
            ex += 1
    print(ans)


if __name__ == "__main__":
    N = int(input())
    pf = p_facto(N)
    main(N)
