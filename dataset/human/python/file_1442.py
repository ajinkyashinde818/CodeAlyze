from strutils import split, parseInt, parseFloat
from sequtils import map

import macros
macro unpack(input: seq; count: static[int]): untyped =
  result = quote do: ()
  when NimMinor <= 13: # 本当にここが区切りかどうかは知らない
    for i in 0..<count: result[0].add quote do: `input`[`i`]
  else:
    for i in 0..<count: result.add quote do: `input`[`i`]

# count == 0 のとき unpackしない
# count >  0 のとき count個分 unpack した結果の tuple を返す
type UnselectableTypeError = object of Exception
template input(typ: typedesc; count: static[Natural] = 0): untyped =
  let line = stdin.readLine.split
  when count == 0:
    when typ is int:    line.map(parseInt)
    elif typ is float:  line.map(parseFloat)
    elif typ is string: line
    else: raise newException(UnselectableTypeError, "You selected a type other than int, float or string")
  else:
    when typ is int:    line.map(parseInt).unpack(count)
    elif typ is float:  line.map(parseFloat).unpack(count)
    elif typ is string: line.unpack(count)
    else: raise newException(UnselectableTypeError, "You selected a type other than int, float or string")

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
from sequtils import mapIt
from strutils import find

let
  (N, M) = input(int, 2)
  A = (1..N).mapIt(input(string, 1))
  B = (1..M).mapIt(input(string, 1))

proc isEq(A, B: seq[string], x, y: int): bool =
  for i in x..(x + B.high):
    for j in y..(y + B[0].high):
      if A[i][j] != B[i - x][j - y]:
        return false
  return true

for i in 0..(A.high - B.high):
  for j in 0..(A[0].high - B[0].high):
    if A.isEq(B, i, j):
      echo "Yes"
      quit()

echo "No"
