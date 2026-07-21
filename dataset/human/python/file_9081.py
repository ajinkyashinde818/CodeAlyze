def resolve():
    S = input()
    pats = ('dream', 'dreamer', 'erase', 'eraser')

    dp = [False for _ in range(len(S) + 1)]
    dp[0] = True
    for i in range(len(S)):
        if not dp[i]:
            continue
        for pat in pats:
            if S[i:i + len(pat)] == pat:
                dp[i + len(pat)] = True
    if dp[-1]:
        print("YES")
    else:
        print("NO")


resolve()
