import sequtils, strutils
import macros
macro unpack(s:seq, n:static[int]): auto =
  let t = genSym()
  result = quote do:(let `t` = `s`;())
  when NimMajor == 0 and NimMinor <= 17:
    for i in 0..<n: result[0][1].add(quote do:(`t`[`i`]))
  else:
    for i in 0..<n: result[1].add(quote do:(`t`[`i`]))

let
  (k, n) = stdin.readline.split.map(parseInt).unpack(2)
  bs = stdin.readline.split.map(parseInt)
var
  ds = newSeq[int](n)

for i in 0..<n:
  ds[i] = (bs[(i+1) mod n] + k - bs[i]) mod k

echo (k-max(ds))
