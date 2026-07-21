import algorithm, future, hashes, macros, math, sequtils, sets, strutils, tables, unicode

template readString: string = stdin.readLine
template readStrings: seq[string] = stdin.readLine.split
template readInt: int = stdin.readLine.parseInt
template readInts: seq[int] = stdin.readLine.split.map(parseInt)
template readFloat: float = stdin.readLine.parseFloat
template readFloats: seq[float] = stdin.readLine.split.map(parseFloat)
template times(n: int, body: untyped): untyped = (for _ in 0..<n: body)
proc newSeq2[T](n1, n2: Natural): seq[seq[T]] = newSeqWith(n1, newSeq[T](n2))
proc newSeq3[T](n1, n2, n3: Natural): seq[seq[seq[T]]] = newSeqWith(n1, newSeqWith(n2, newSeq[T](n3)))

macro unpack*(rhs: seq, cnt: static[int]): auto =
  let t = genSym(); result = quote do:(let `t` = `rhs`;())
  for i in 0..<cnt: result[0][1].add(quote do:`t`[`i`])

# --------------------------------------------------- #

var (D, G) = readInts.unpack(2)
var P, C = newSeq[int](D + 1)
for i in 1..D:
  (P[i], C[i]) = readInts.unpack(2)

proc main =
  var res = 10000
  for bit in 0..<(1 shl D):
    var score, cnt, nottry = 0
    for i in 1..D:
      if ((bit shr (i - 1)) and 1) == 1:
        score += 100 * i * P[i] + C[i]
        cnt += P[i]
      else:
        nottry = i

    for j in 0..<P[nottry]:
      if score < G:
        score += 100 * nottry
        cnt += 1
      else:
        break

    if score >= G:
      res = min(res, cnt)

  echo res

main()
