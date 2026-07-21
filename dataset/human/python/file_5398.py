import strutils
import sequtils
import algorithm
import math
import sets
import hashes
import tables
import macros

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

var N = readString
if N[0] == '9' or N[1] == '9':
  echo "Yes"
else:
  echo "No"
