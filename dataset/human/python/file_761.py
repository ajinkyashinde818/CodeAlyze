import algorithm, complex, macros, math, sequtils, sets, strutils, tables, times
when NimMajor == 0 and NimMinor <= 19:
  import future
else:
  import sugar, strformat

macro unpack*(rhs: seq, cnt: static[int]): auto =
  let v = genSym(); result = quote do:(let `v` = `rhs`;())
  when NimMajor == 0 and NimMinor <= 17:
    for i in 0 ..< cnt: result[0][1].add(quote do:`v`[`i`])
  else:
    for i in 0 ..< cnt: result[1].add(quote do:`v`[`i`])

template input*(T: typedesc, cnt: Natural = 1): untyped =
  let line = stdin.readLine.split(" ")
  when T is int:         line.map(parseInt).unpack(cnt)
  elif T is float:       line.map(parseFloat).unpack(cnt)
  elif T is string:      line.unpack(cnt)
  elif T is char:        line.mapIt(it[0]).unpack(cnt)
  elif T is seq[int]:    line.map(parseint)
  elif T is seq[float]:  line.map(parseFloat)
  elif T is seq[string]: line
  elif T is seq[char]:   line.mapIt(it[0])

macro dump*(arg: varargs[untyped]): untyped =
  result = newNimNode(nnkStmtList)
  for x in arg:
    let name = toStrLit(x)
    result.add(quote do: stderr.write `name`, " = " , `x`, "\n")

proc `|=`*(n: var int, m: int) = n = n or m
proc `|=`*(n: var bool, m: bool) = n = n or m
proc `&=`*(n: var int, m: int) = n = n and m
proc `&=`*(n: var bool, m: bool) = n = n and m
proc `^=`*(n: var int, m: int) = n = n xor m
proc `^=`*(n: var bool, m: bool) = n = n xor m
proc `%=`*(n: var int, m: int) = n = n mod m
proc `/=`*(n: var int, m: int) = n = n div m
proc `<<=`*(n: var int, m: int) = n = n shl m
proc `>>=`*(n: var int, m: int) = n = n shr m
proc `<?=`*(n: var SomeNumber, m: SomeNumber) = n = min(n, m)
proc `>?=`*(n: var SomeNumber, m: SomeNumber) = n = max(n, m)
proc newSeq2*[T](n1, n2: Natural): seq[seq[T]] = newSeqWith(n1, newSeq[T](n2))
proc newSeq3*[T](n1, n2, n3: Natural): seq[seq[seq[T]]] = newSeqWith(n1, newSeqWith(n2, newSeq[T](n3)))
proc newSeq4*[T](n1, n2, n3, n4: Natural): seq[seq[seq[seq[T]]]] = newSeqWith(n1, newSeqWith(n2, newSeqWith(n3, newSeq[T](n4))))

# -------------------------------------------------- #

var (N, R) = input(int, 2)
if N >= 10:
  echo R
else:
  echo R + 100 * (10 - N)
