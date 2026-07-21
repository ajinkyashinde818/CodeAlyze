import algorithm, future, hashes, macros, math, sequtils, sets, strutils, tables, unicode

template readString: string = stdin.readLine
template readStrings: seq[string] = stdin.readLine.split
template readInt: int = stdin.readLine.parseInt
template readInts: seq[int] = readLine(stdin).split(" ").map(parseInt)
template readFloat: float = stdin.readLine.parseFloat
template readFloats: seq[float] = stdin.readLine.split.map(parseFloat)
template times(n: int, body: untyped): untyped = (for _ in 0..<n: body)
proc newSeq2[T](n1, n2: Natural): seq[seq[T]] = newSeqWith(n1, newSeq[T](n2))
proc newSeq3[T](n1, n2, n3: Natural): seq[seq[seq[T]]] = newSeqWith(n1, newSeqWith(n2, newSeq[T](n3)))
macro unpack*(rhs: seq, cnt: static[int]): auto =
  let t = genSym(); result = quote do:(let `t` = `rhs`;())
  for i in 0..<cnt: result[0][1].add(quote do:`t`[`i`])

# -------------------------------------------------- #

var S = readString

var removed = newseq[char]()
for i in 0..<S.len:
  if S[i] == 'x':
    continue
  else:
    removed.add(S[i])

if removed != removed.reversed:
  echo "-1"
  quit()

var res = 0
var i = 0
var j = S.len - 1

while i < j:
  if S[i] == S[j]:
    inc(i)
    dec(j)
  elif S[i] == 'x':
    inc(res)
    inc(i)
  elif S[j] == 'x':
    inc(res)
    dec(j)

echo res
