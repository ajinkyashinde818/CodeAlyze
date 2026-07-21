def main():
    s = input()
    s = list(reversed(s))
    s.append('0')
    dp = [[10**10 for _ in range(2)] for _ in range(len(s)+1)]
    dp[0][0] = 0
    for i in range(len(s)):
        for j in range(2):
            x = int(s[i])
            x += j
            for a in range(10):
                ni = i+1
                nj = 0
                b = a-x
                if b < 0:
                    nj = 1
                    b += 10
                dp[ni][nj] = min(dp[ni][nj], dp[i][j]+a+b)
    print(dp[len(s)][0])


main()
