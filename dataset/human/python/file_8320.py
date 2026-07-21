import strutils, sequtils,math

var K, N: int
(K, N) = map(readLine(stdin).split(), parseInt)
var A = map(readLine(stdin).split(), parseInt)
A.add(K + A[0])
var answer: int = 10 ^ 9 + 7
for i in 0..<N:
    answer = min(answer, K - A[i + 1] + A[i])
echo answer
