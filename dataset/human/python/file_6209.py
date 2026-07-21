import strutils, sequtils, math, algorithm, tables, sets, lists, intsets, critbits, sugar
const INF = 10 ^ 10
var S = stdin.readLine.toSeq.reversed
S &= '0'

var n = S.len
var dp = newSeqWith(n + 1, newSeqWith(2, INF))
dp[0][0] = 0
for i in (0..<n):
    for j in (0..1):
        var x = int(S[i]) - int('0')
        x += j
        if x < 10:
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + x)
        if x > 0:
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][j] + (10 - x))
echo dp[n][0]
