def main():
    N, K, S = map(int, input().split())
    ans = [10 ** 9] * N
    cnt = 0
    if N == K:
        for i in range(K):
            ans[i] = S
        print(*ans)
        exit()
    if S == 1:
        for i in range(K):
            ans[i] = 1
        print(*ans)
        exit()
    if S == 10 ** 9:
        ans = [2] * N
    ans[0] = 1
    for i in range(1,K+1):
        if i % 2 == 1:
            ans[i] = S - 1
        else:
            ans[i] = 1

    print(*ans) 


if __name__ == "__main__":
    main()
