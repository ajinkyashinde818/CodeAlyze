def main():
    N, K, S = map(int, input().split())

    dummy = 10**9 - 1 if S == 10**9 else 10**9

    ans = []
    for _ in range(K):
        ans.append(str(S))

    for _ in range(N - K):
        ans.append(str(dummy))

    print(" ".join(ans))


main()
