import sequtils, strutils, algorithm

const
  ws = ["dream", "dreamer", "erase", "eraser"]
  rs = ws.mapIt(toSeq(it.items).reversed.mapIt($it).join)
  sz = ws.mapIt(len(it))
let
  s = stdin.readline
  r = toSeq(s.items).reversed.mapIt($it).join
  n = len(s)
var
  j = 0
  ok = true

while ok:
  ok = false
  for rn in zip(rs, sz):
    if j+rn[1]<=n and r[j..<(j+rn[1])]==rn[0]:
      j += rn[1]
      ok = true
      break
  
if j!=n:
  echo "NO"
else:
  echo "YES"
