import strutils, sequtils, parseutils

let
  ks = readLine(stdin).split(" ").map(parseInt)
  k = ks[0]
  s = ks[1]

var ans = 0
for i in 0..min(k, s):
  if s-i > k*2:
    continue
  for j in 0..min(k, s-i):
    if s-i-j <= k:
      ans += 1
echo ans
