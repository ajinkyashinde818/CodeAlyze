import strutils, math

proc input: string =
  while true:
    let tmp = readChar stdin
    if not isSpace tmp:
      safeAdd result, tmp
    elif tmp != '\r': break

type
  cnddt = tuple[used: seq[int], cnt, points: int]
let
  D, G = parseInt input()
var
  prblms = newSeq[tuple[p, c: int]](D)
  cnddts = newSeq[cnddt]()
  ans = newSeq[int]()

for i, v in prblms:
  prblms[i] = (parseInt input(), parseInt input())

proc fn(n: int): cnddt =
  result.used = @[]
  var j = n
  for i in 0 ..< D:
    let unit = (i + 1) * 100
    if j mod 2 == 0:
      add result.used, i
      result.cnt += prblms[i].p
      result.points += prblms[i].c + unit * prblms[i].p
    j = j div 2

for i in 0 ..< 2 ^ D:
  add cnddts, i.fn

for i in 0 ..< D:
  for j, v in cnddts:
    let
      unit = (i + 1) * 100
      k = G - v.points
    if k <= 0:
      add ans, v.cnt
    elif i notin v.used and k <= unit * (prblms[i].p - 1):
      add ans, v.cnt + k div unit + int(k mod unit != 0)

echo min ans
