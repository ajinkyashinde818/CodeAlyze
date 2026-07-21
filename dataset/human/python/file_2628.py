def main():
    D, G = map(int, input().split())
    P = [0] * (D+1)
    C = [0] * (D+1)
    for i in range(1, D+1):
        P[i], C[i] = map(int, input().split())
    dp = [(0, [0]*(D+1))] * (sum(P) + 1)
    dp[0] = (0, P)
    for i in range(sum(P) + 1):
        score, remain = dp[i]
        for prob in range(1, D+1):
            for j in range(1, remain[prob]+1):
                next_score = score + prob * j * 100
                if j == remain[prob]:
                    next_score += C[prob]
                if dp[i+j][0] < next_score:
                    next_remain = [x for x in remain]
                    next_remain[prob] -= j
                    dp[i+j] = (next_score, next_remain)
    for i in range(len(dp)):
        if dp[i][0] >= G:
            print(i)
            break


if __name__ == "__main__":
    main()
