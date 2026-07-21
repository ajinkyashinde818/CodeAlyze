import sys

if __name__ == '__main__':
    S = sys.stdin.readline().rstrip()

    ls = ['dream', 'dreamer', 'erase', 'eraser']
    lenS = len(S)
    dp = [False for i in range(lenS + 10)]

    dp[0] = True

    for i in range(lenS):
        if not dp[i]:
            continue

        for w in ls:
            if S[i:i+len(w)] == w:
                dp[i+len(w)] = True

    r = 'YES' if dp[len(S)] else 'NO'

    print(r)
