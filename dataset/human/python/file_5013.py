import sequtils, strutils

let
  nm = stdin.readline.split.map(parseInt)
  (n, m) = (nm[0], nm[1])
var
  ss,ts = newSeq[bool](n)

for _ in 1..m:
  let ab = stdin.readline.split.map(parseInt)
  if ab[0] == 1:
    ss[ab[1]-1] = true
  elif ab[0] == n:
    ts[ab[1]-1] = true
  if ab[1] == 1:
    ss[ab[0]-1] = true
  elif ab[1] == n:
    ts[ab[0]-1] = true

var possible = false
for i in 1..<(n-1):
  if ss[i] and ts[i]:
    possible = true
    break
if possible:
  echo "POSSIBLE"
else:
  echo "IMPOSSIBLE"
