import sys
S = sys.stdin.readline().strip()
dp = [False] * (len(S) + 1)
dp[0] = True

ws = ['dream', 'dreamer' ,'erase' ,'eraser']
for i, c in enumerate(S):
    for w in ws:
        j = i-len(w) + 1
        if j >= 0 and dp[j] and S[j:i+1] == w:
            dp[i+1] = True
        if dp[i+1]:
            break
print('YES' if dp[len(S)] else 'NO')
