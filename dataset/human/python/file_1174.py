import sequtils, strutils, math

let
  n = stdin.readline.parseInt
  bs = stdin.readline.split.map(parseInt)
  s = sum(bs)
var
  cs = bs
  res = 1 shl 60
for i in 1..<n:
  cs[i] += cs[i-1]

for i in 0..<(n-1):
  res = min(res, abs(cs[i]*2-s))

echo res
