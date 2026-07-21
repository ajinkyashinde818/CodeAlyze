def main():
    MAX = 10**9

    N, K, S = tuple(int(i) for i in input().split())

    if S == MAX:
        ans = [S - 1 for _ in range(N)]
        for i in range(N):
            if i < K:
                ans[i] = S

        print(" ".join([str(i) for i in ans]))
    else:
        ans = [S + 1 for _ in range(N)]
        for i in range(N):
            if i < K:
                ans[i] = S

        print(" ".join([str(i) for i in ans]))


if __name__ == '__main__':
    main()
