import algorithm, future, hashes, macros, math, sequtils, sets, strutils, tables, unicode

template readString: string = stdin.readLine
template readStrings: seq[string] = stdin.readLine.split
template readInt: int = stdin.readLine.parseInt
template readInts: seq[int] = stdin.readLine.split.map(parseInt)
template readFloat: float = stdin.readLine.parseFloat
template readFloats: seq[float] = stdin.readLine.split.map(parseFloat)
proc newSeq2[T](n1, n2: Natural): seq[seq[T]] = newSeqWith(n1, newSeq[T](n2))
proc newSeq3[T](n1, n2, n3: Natural): seq[seq[seq[T]]] = newSeqWith(n1, newSeqWith(n2, newSeq[T](n3)))

macro unpack*(rhs: seq, cnt: static[int]): auto =
  let t = genSym(); result = quote do:(let `t` = `rhs`;())
  for i in 0..<cnt: result[0][1].add(quote do:`t`[`i`])

# --------------------------------------------------- #

var N = readint
var A = readints
var S = newseq[int](N)
S[0] = A[0]
var res = 0x3f3f3f3f3f3f3f3f
for i in 1..<N:
  S[i] = S[i - 1] + A[i]
for i in 0..(N - 2):
  res = min(res, abs(S[N - 1] - S[i] - S[i]))
echo res
