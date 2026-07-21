from strutils import split, parseInt, parseFloat
from sequtils import map

import macros
macro unpack*(input: seq; count: static[int]): untyped =
  result = quote do: ()
  when NimMinor <= 13: # 本当にここが区切りかどうかは知らない
    for i in 0..<count: result[0].add quote do: `input`[`i`]
  else:
    for i in 0..<count: result.add quote do: `input`[`i`]

# count == 0 のとき unpackしない
# count >  0 のとき count個分 unpack した結果の tuple を返す
type UnselectableTypeError = object of Exception
template input*(typ: typedesc; count: static[Natural] = 0): untyped =
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
from math import sum

let
  N = input(int, 1)
  a = input(int, 0)

var
  sunuke = a[0]
  arai = a[1..^1].sum

var result = (arai - sunuke).abs
for v in a[1..^2]:
  sunuke += v
  arai -= v
  result = min(result, (arai - sunuke).abs)

echo result
