import strutils, sequtils
var N, M: int; (N, M) = stdin.readLine.split.map parseInt
let As = (1 .. N).mapIt(stdin.readLine)
let Bs = (1 .. M).mapIt(stdin.readLine)
for i in 0 .. N - M:
  for j in 0 .. N - M:
    var b = true
    for y in 0 ..< M:
      if As[i + y][j .. j + M - 1] != Bs[y]: b = false
    if b: echo "Yes"; quit()
echo "No"
