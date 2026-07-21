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

template input*(typ: typedesc, cnt: Natural = 1): untyped =
  let line = stdin.readLine.split(" ")
  when typ is int:    line.map(parseInt).unpack(cnt)
  elif typ is float:  line.map(parseFloat).unpack(cnt)
  elif typ is string: line.unpack(cnt)
  elif typ is char:   line.mapIt(it[0]).unpack(cnt)

template inputs*(typ: typedesc): untyped =
  let line = stdin.readLine.split(" ")
  when typ is int:    line.map(parseInt)
  elif typ is float:  line.map(parseFloat)
  elif typ is string: line
  elif typ is char:   line.mapIt(it[0])

# -------------------------------------------------- #

var N = input(int)

var k = 0

for i in countup(1, N + 1):
  if i * (i - 1) div 2 == N:
    k = i
    break

if k == 0:
  echo "No"
else:
  var first = 1
  var b = k
  var toidx = newseqwith(N + 1, newseq[int]())
  var i = 1
  while i <= N and b > 1:
    for j in countup(i, i + b - 2):
      toidx[j].add(first)
      var second = j - i + 1 + first
      toidx[j].add(second)
    inc first
    dec b
    i += b
  var S = newseqwith(k + 1, newseq[int]())
  for i in countup(1, N):
    for e in toidx[i]:
      S[e].add(i)
  
  echo "Yes"
  echo k
  for i in countup(1, k):
    echo k - 1, " ", S[i].mapIt($it).join(" ")
