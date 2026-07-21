def test():
    s = input()
    divide = ["dream", "dreamer", "erase", "eraser"]
    dp = [0 for i in range(100010)]

    dp[0] = 1
    for i in range(len(dp)):
        if dp[len(s)] == 1:
            print('YES')
            return 0
        if dp[i] == 0:
            continue
        for d in divide:
            if s[i:i+len(d)] == d:
                dp[i+len(d)] = 1
    print('NO')

test()
