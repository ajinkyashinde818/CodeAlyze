def main():
    N = int(input())
    a = list(map(int, input().split()))

    s = [0] * N
    s[0] = a[0]
    sr = [0] * N
    sr[0] = a[-1]

    for i in range(1, N):
        s[i] = s[i-1] + a[i]
        sr[i] = sr[i-1] + a[N-i-1]

    ans = 10 ** 18
    for i in range(N-1):
        tmp = abs(s[i] - sr[N-i-2])
        if tmp < ans:
            ans = tmp

    print(ans)


if __name__ == "__main__":
    main()
