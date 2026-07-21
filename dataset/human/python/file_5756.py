import sequtils,strutils,math
var
    N = stdin.readline.parseInt
    A = stdin.readline.split.map(parseInt)
    B = stdin.readline.split.map(parseInt)
    C = stdin.readline.split.map(parseInt)
    ans = B.sum
for i in 0..<N:
    if i + 1 < N and A[i] + 1 == A[i + 1]:
        ans += C[A[i] - 1]

echo ans
