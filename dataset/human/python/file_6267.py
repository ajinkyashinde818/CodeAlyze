def main():
    import sys
    input = sys.stdin.readline

    S_raw = input().rstrip('\n')

    S = [int(s) for s in S_raw]
    N = len(S)
    ans = 0
    dp0 = [0] * (N+1)
    dp1 = [0] * (N+1)
    dp1[0] = 1
    for i in range(N):
        s = S[i]
        dp0[i+1] = min(dp0[i] + s, dp1[i] + s+1)
        dp1[i+1] = min(dp1[i] + min(s+2, 9-s), dp0[i] + 1 + min(s, 10-s))
    print(min(dp0[-1], dp1[-1]+1))


if __name__ == '__main__':
    main()
