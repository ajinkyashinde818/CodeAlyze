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
  (n, m) = stdin.readline.split.map(parseInt).unpack(2)
  bs = newSeqWith(n, stdin.readline)
  cs = newSeqWith(m, stdin.readline)

for i in 0..(n-m):
  for j in 0..(n-m):
    var matched = true
    for k in 0..<m:
      if bs[i+k][j..<(j+m)] != cs[k]:
        matched = false
        break
    if matched:
      echo "Yes"
      quit()
echo "No"
