import sequtils, strutils, math, algorithm

let
  n = stdin.readline.parseInt
  bs = stdin.readline.split.map(parseInt)
  pos = bs.filterIt(it > 0)
  neg = bs.filterIt(it <= 0)
  s = pos.sum - neg.sum

if len(neg) mod 2 == 0:
  echo s
elif len(pos) == 0:
  echo (s + neg.max*2)
else:
  echo max(s + neg.max*2, s - pos.min*2)
