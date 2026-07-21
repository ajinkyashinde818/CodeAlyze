mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    def PrimeDecomposition(N):
        ret = {}
        n = int(N ** 0.5)
        for d in range(2, n + 1):
            while N % d == 0:
                if d not in ret:
                    ret[d] = 1
                else:
                    ret[d] += 1
                N //= d
            if N == 1:
                break
        if N != 1:
            ret[N] = 1
        return ret

    N = int(input())
    P = PrimeDecomposition(N)
    ans = 0
    for d in P:
        a = P[d]
        for i in range(1, 100):
            if a >= i:
                a -= i
                ans += 1
            else:
                break
    print(ans)


if __name__ == '__main__':
    main()
