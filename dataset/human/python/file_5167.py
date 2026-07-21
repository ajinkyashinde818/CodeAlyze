def main():
    N, M = map(int, input().split())
    AB = []
    for _ in range(M):
        a, b = map(int, input().split())
        AB.append([a, b])

    F = [0] * N
    S = [0] * N
    
    for a, b in AB:
        if a == 1:
            F[b] = True
        if b == N:
            S[a] = True

    # print(F)
    # print(S)

    ans = 'IMPOSSIBLE'
    for i in range(N):
        if F[i] and S[i]:
            ans = 'POSSIBLE'
    print(ans)


if __name__ == "__main__":
    main()
