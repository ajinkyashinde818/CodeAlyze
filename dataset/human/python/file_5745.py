import sequtils, strutils, algorithm, math

var N = stdin.readline.parseInt
var A,B,C = stdin.readline.split.map(parseInt)

var ans = 0
var prev = 100
for i in 0..<N:
  ans += B[A[i]-1]
  if prev == (A[i]-2):
    ans += C[prev]
  prev = A[i]-1

echo ans
