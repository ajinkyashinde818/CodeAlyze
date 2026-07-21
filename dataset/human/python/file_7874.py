def main():
    N, K, S = map(int, input().split())

    if S == 10**9:
        for i in range(N):
            if i < K:
                print(S, end=" ")
            elif i == (N-1):
                print(1)
            else:
                print(1, end=" ")
    else:
        for i in range(N):
            if i < K:
                print(S, end=" ")
            elif i == (N-1):
                print(S+1)
            else:
                print(S+1, end=" ")
    return 0

if __name__ == '__main__':
    main()
