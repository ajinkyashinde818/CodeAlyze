import algorithm, future, hashes, macros, math, sequtils, sets, strutils, tables, times, unicode

proc `%=`(n: var int, m: int)  = n = n mod m
proc `//=`(n: var int, m: int) = n = n div m
proc `<<=`(n: var int, m: int) = n = n shl m
proc `>>=`(n: var int, m: int) = n = n shr m
proc `<?=`(n: var int, m: int) = n = min(n, m)
proc `>?=`(n: var int, m: int) = n = max(n, m)

macro unpack*(rhs: seq, cnt: static[int]): auto =
  let t = genSym(); result = quote do:(let `t` = `rhs`;())
  if NimMinor <= 17:
    for i in 0..<cnt: result[0][1].add(quote do:`t`[`i`])
  else:
    for i in 0..<cnt: result[1].add(quote do:`t`[`i`])

template input*(typ: typedesc, cnt: Natural = 0): untyped =
  let line = stdin.readLine.split(" ")
  when cnt == 0:
    when typ is int:    line.map(parseInt)
    elif typ is float:  line.map(parseFloat)
    elif typ is string: line
    elif typ is char:   line.mapIt(it[0])
  else:
    when typ is int:    line.map(parseInt).unpack(cnt)
    elif typ is float:  line.map(parseFloat).unpack(cnt)
    elif typ is string: line.unpack(cnt)
    elif typ is char:   line.mapIt(it[0]).unpack(cnt)

# -------------------------------------------------- #

var S = input(string, 1)
var (x, y) = input(int, 2)
var xmax, ymax = 0
var pari = true
for s in S:
  if s == 'F':
    if pari:
      inc xmax
    else:
      inc ymax
  elif s == 'T':
    pari = not pari

const geta = 8000
var dpx = newseq[bool](16001)
var dpy = newseq[bool](16001)
dpx[geta] = true
dpy[geta] = true

proc clear(dp: var seq[bool], max: int) =
  for i in countup(-max, max):
    dp[i + geta] = false
proc update1(cnt: int, dp: seq[bool], max: int): seq[int] =
  result = newseq[int]()
  for i in countdown(max, -max + cnt):
    if dp[i - cnt + geta]:
      result.add(i)
proc update2(cnt: int, dp: seq[bool], max: int): seq[int] =
  result = newseq[int]()
  for i in countup(-max, max - cnt):
    if dp[i + cnt + geta]:
      result.add(i)

var dir = 0
var cnt = 0
S.add('T')
for s in S:
  if s == 'T':
    if cnt == 0:
      inc dir
      continue
    if dir == 0:
      var up = update1(cnt, dpx, xmax)
      dpx.clear(xmax)
      for e in up:
        dpx[e + geta] = true
    elif dir mod 2 == 0:
      var up = update1(cnt, dpx, xmax)
      var down = update2(cnt, dpx, xmax)
      dpx.clear(xmax)
      for e in up:
        dpx[e + geta] = true
      for e in down:
        dpx[e + geta] = true
    else:
      var up = update1(cnt, dpy, ymax)
      var down = update2(cnt, dpy, ymax)
      dpy.clear(ymax)
      for e in up:
        dpy[e + geta] = true
      for e in down:
        dpy[e + geta] = true
    cnt = 0
    inc dir
  elif s == 'F':
    inc cnt

if dpx[x + geta] and dpy[y + geta]:
  echo "Yes"
else:
  echo "No"
