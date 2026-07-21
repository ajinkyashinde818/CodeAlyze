import sequtils, strutils, macros

macro unpack(s:seq, n:static[int]): auto =
  let t = genSym()
  result = quote do:(let `t`=`s`;())
  for i in 0..<n:
    result[0][1].add(quote do:(`t`[`i`]))

let
  (d, g) = stdin.readline.split.map(parseInt).unpack(2)
  pcs = newSeqWith(d, stdin.readline.split.map(parseInt).unpack(2))
var
  completes = newSeq[int](d)
  ps = newSeq[int](d)

for i,pc in pcs:
  let (p, c) = pc
  completes[i] = p*(i+1)*100 + c
  ps[i] = p

proc f(b: int): int =
  var t,n = 0
  for i in 0..<d:
    if (b shr i and 1) == 1:
      t += completes[i]
      n += ps[i]
  if t < g:
    for i in countdown(d-1, 0):
      if (b shr i and 1) == 0 and g-t <= (i+1)*100*ps[i]:
        return n + (g-t+(i+1)*100-1) div ((i+1)*100)
    return 1 shl 30
  return n

var res = 1 shl 30
for b in 0..<(1 shl d):
  res = min(res, f(b))

echo res
