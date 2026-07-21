import strutils, sequtils, math
let n = stdin.readLine.parseInt
let a, b, c = stdin.readLine.split.map(parseInt)
var m = b[a[0]-1]
for i in 1..n-1:
  m += b[a[i]-1]
  if a[i]-a[i-1]==1:
    m += c[a[i]-2]
echo m
