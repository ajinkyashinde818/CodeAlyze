import strutils, sequtils

var tokens = stdin.readLine.split.map(parseInt)
let
  k = tokens[0]
  n = tokens[1]
  a = stdin.readLine.split.map(parseInt)

var ans = k

for i in 0..<n:
  let
    prev = (i + n - 1) mod n
    next = (i + 1) mod n
    prevDist = (a[i] + k - a[prev]) mod k
    nextDist = (a[next] + k - a[i]) mod k
  
  if k - max(prevDist, nextDist) < ans:
    ans = k - max(prevDist, nextDist)

echo ans
