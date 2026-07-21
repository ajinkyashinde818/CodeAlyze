import sequtils, strutils, math

let
  n = stdin.readline.parseInt
  a = stdin.readline.split.map(parseInt)
  b = stdin.readline.split.map(parseInt)
  c = stdin.readline.split.map(parseInt)
var
  res = sum(b)

for i in 1..<n:
  if a[i-1]+1 == a[i]:
    res += c[a[i-1]-1]

echo res
