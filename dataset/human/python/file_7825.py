def solve():
    N, K, S = map(int, input().split())
    Ans = [0] * N
    for i in range(K):
        Ans[i] = S
    for i in range(K, N):
        Ans[i] = (S + 1 if S < 10 ** 9 else 1)

    print(" ".join(map(str, Ans)))
    return 0

if __name__ == "__main__":
    solve()
