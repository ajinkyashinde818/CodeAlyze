import algorithm, complex, future, macros, math, sequtils, sets, strutils, tables

macro unpack(rhs: seq, cnt: static[int]): auto =
  let v = genSym(); result = quote do:(let `v` = `rhs`;())
  if NimMinor <= 17:
    for i in 0..<cnt: result[0][1].add(quote do:`v`[`i`])
  else:
    for i in 0..<cnt: result[1].add(quote do:`v`[`i`])

template input(T: typedesc, cnt: Natural = 1): untyped =
  let line = stdin.readLine.split(" ")
  when T is int:         line.map(parseInt).unpack(cnt)
  elif T is float:       line.map(parseFloat).unpack(cnt)
  elif T is string:      line.unpack(cnt)
  elif T is char:        line.mapIt(it[0]).unpack(cnt)
  elif T is seq[int]:    line.map(parseint)
  elif T is seq[float]:  line.map(parseFloat)
  elif T is seq[string]: line
  elif T is seq[char]:   line.mapIt(it[0])

proc `<?=`(n: var SomeNumber, m: SomeNumber) = n = min(n, m)
proc `>?=`(n: var SomeNumber, m: SomeNumber) = n = max(n, m)
proc newSeq2[T](n1, n2: Natural): seq[seq[T]] = newSeqWith(n1, newSeq[T](n2))
proc newSeq3[T](n1, n2, n3: Natural): seq[seq[seq[T]]] = newSeqWith(n1, newSeqWith(n2, newSeq[T](n3)))

# -------------------------------------------------- #

var N = input(int)
if N mod 2 == 1:
  echo 0
else:
  var res = 0
  var k = 5
  while true:
    var cnt = N div k
    #echo k, " ", cnt
    if cnt == 0:
      break
    else:
      res += cnt div 2
      # if k == 10 ^ 18:
      #   break
      k *= 5
  echo res
