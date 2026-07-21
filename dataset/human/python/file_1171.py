import strutils, sequtils, math

let
  N = parseInt readLine stdin
  a = map(split readLine stdin, parseInt)
  a_sum = a.sum
var
  x = 0
  best = int.high

for i, v in a[0 .. ^2]:
  x += v
  let y = a_sum - x
  best = min(best, abs(x - y))

echo best
