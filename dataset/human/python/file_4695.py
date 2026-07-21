import algorithm, hashes, macros, math, sequtils, sets, strutils, tables, unicode

template readString: string = stdin.readLine
template readStrings: seq[string] = stdin.readLine.split
template readInt: int = stdin.readLine.parseInt
template readInts: seq[int] = stdin.readLine.split.map(parseInt)
template readInt64: int64 = stdin.readLine.parseBiggestInt
template readInt64s: seq[int64] = stdin.readLine.split.map(parseBiggestInt)
template readFloat: float = stdin.readLine.parseFloat
template readFloats: seq[float] = stdin.readLine.split.map(parseFloat)
template times(n: int, body: untyped): untyped = (for _ in 0..<n: body)

proc toString(str: seq[char]): string =
  result = newStringOfCap(str.len)
  for ch in str: add(result, ch)

macro unpack*(rhs: seq, cnt: static[int]): auto =
  let t = genSym(); result = quote do:(let `t` = `rhs`;())
  for i in 0..<cnt: result[0][1].add(quote do:`t`[`i`])

# --------------------------------------------------- #

var s = readString.sorted(cmp).toString
var t = readString.sorted(cmp).reversed.toString
if s < t:
  echo "Yes"
else:
  echo "No"
