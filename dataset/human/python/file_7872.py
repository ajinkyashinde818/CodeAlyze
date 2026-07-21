def main():
    import sys
    input = sys.stdin.readline

    N, K, S = map(int, input().split())

    if S < 10**9:
        ans = [10**9] * N
        for i in range(K):
            ans[i] = S
    else:
        ans = [1] * N
        for i in range(K):
            ans[i] = S
    print(*ans)


if __name__ == '__main__':
    main()
