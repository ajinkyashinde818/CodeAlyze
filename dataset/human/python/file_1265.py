def main():
    N = int(input())
    A = [int(i) for i in input().split()]
    from itertools import accumulate
    S = list(accumulate([0] + A))
    ans = 10**18
    for i in range(1, N):
        snuke = S[i] - S[0]
        arai = S[N] - S[i]
        cur = abs(snuke - arai)
        ans = min(ans, cur)
    print(ans)


if __name__ == '__main__':
    main()
