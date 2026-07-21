import algorithm, future, hashes, macros, math, sequtils, sets, strutils, tables, times, unicode, queues

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
proc `<?=`(n: var int, m: int) = n = min(n, m)
proc `>?=`(n: var int, m: int) = n = max(n, m)
proc newSeq2[T](n1, n2: Natural): seq[seq[T]] = newSeqWith(n1, newSeq[T](n2))
proc newSeq3[T](n1, n2, n3: Natural): seq[seq[seq[T]]] = newSeqWith(n1, newSeqWith(n2, newSeq[T](n3)))

# -------------------------------------------------- #

proc main() =
  var (N, C) = input(int, 2)
  var X, V, Y, U = newseq[int](N + 1)
  for i in countup(1, N):
    (X[i], V[i]) = input(int, 2)
    Y[N - i + 1] = C - X[i]
    U[N - i + 1] = V[i]
  var res = 0
  var sum = 0
  var sumr = 0
  var best = newseq[int](N + 1)
  var bestr = newseq[int](N + 1)
  for i in countup(1, N):
    sum += V[i] - (X[i] - X[i - 1])
    sumr += U[i] - (Y[i] - Y[i - 1])
    best[i] = max(best[i - 1], sum)
    bestr[i] = max(bestr[i - 1], sumr)
    res = max([res, best[i], bestr[i]])
  sum = 0
  sumr = 0
  var best2 = newseq[int](N + 1)
  var best2r = newseq[int](N + 1)
  for i in countup(1, N):
    sum += V[i] - 2 * (X[i] - X[i - 1])
    sumr += U[i] - 2 * (Y[i] - Y[i - 1])
    best2[i] = max(best2[i - 1], sum)
    best2r[i] = max(best2r[i - 1], sumr)
    res = max([res, best2[i] + bestr[N - i], best2r[i] + best[N - i]])
  echo res

main()
