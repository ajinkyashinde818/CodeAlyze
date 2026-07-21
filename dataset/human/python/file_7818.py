if __name__ == "__main__":
    N, K, S = map(int, input().split())
    for _ in range(K):
        print(S, end=" ")
    if S == 10**9:
        for _ in range(N-K):
            print(S-1, end=" ")
    else:
        for _ in range(N-K):
            print(S+1, end=" ")
    print()
