import algorithm, future, macros, math, sequtils, sets, strutils, tables

macro unpack(rhs: seq, cnt: static[int]): auto =
  let t = genSym(); result = quote do:(let `t` = `rhs`;())
  if NimMinor <= 17:
    for i in 0..<cnt: result[0][1].add(quote do:`t`[`i`])
  else:
    for i in 0..<cnt: result[1].add(quote do:`t`[`i`])

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

proc `%=`(n: var int, m: int)  = n = n mod m
proc `//=`(n: var int, m: int) = n = n div m
proc `<<=`(n: var int, m: int) = n = n shl m
proc `>>=`(n: var int, m: int) = n = n shr m
proc `<?=`(n: var SomeNumber, m: SomeNumber) = n = min(n, m)
proc `>?=`(n: var SomeNumber, m: SomeNumber) = n = max(n, m)
proc newSeq2[T](n1, n2: Natural): seq[seq[T]] = newSeqWith(n1, newSeq[T](n2))
proc newSeq3[T](n1, n2, n3: Natural): seq[seq[seq[T]]] = newSeqWith(n1, newSeqWith(n2, newSeq[T](n3)))

# -------------------------------------------------- #

var S = input(string)
echo S[0 .. ^9]
