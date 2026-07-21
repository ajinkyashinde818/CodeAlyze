import strutils
import sequtils
import algorithm
import math
import sets
import hashes
import tables
import macros
import unicode

template readString: string = stdin.readLine
template readStrings: seq[string] = stdin.readLine.split
template readInt: int = stdin.readLine.parseInt
template readInts: seq[int] = stdin.readLine.split.map(parseInt)
template readInt64: int64 = stdin.readLine.parseBiggestInt
template readInt64s: seq[int64] = stdin.readLine.split.map(parseBiggestInt)
template readFloat: float = stdin.readLine.parseFloat
template readFloats: seq[float] = stdin.readLine.split.map(parseFloat)
template times(n: int, body: untyped): untyped = (for _ in 0..<n: body)

macro unpack*(rhs: seq, cnt: static[int]): auto =
  let t = genSym(); result = quote do:(let `t` = `rhs`;())
  for i in 0..<cnt: result[0][1].add(quote do:`t`[`i`])

# --------------------------------------------------- #

var (X, Y) = readStrings.unpack(2)
var (x, y) = (X[0], Y[0])
if x < y:
  echo "<"
elif x == y:
  echo "="
else:
  echo ">"
