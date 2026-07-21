import sequtils, strutils, math, algorithm, tables

var
  n = parseInt(readLine(stdin))
  a = readLine(stdin).split().map(parseBiggestInt)
  ans:int64 = 0
  count = 0

for i in 0..<n:
  if a[i] < 0:
    inc(count)
if count mod 2 == 0:
  for i in 0..<n:
    ans = ans + abs(a[i])
else:
  var min:int64 = 10^9+1
  for i in 0..<n:
    if min > abs(a[i]):
      min = abs(a[i])
  for i in 0..<n:
    ans = ans + abs(a[i])
  ans = ans - 2 * min

echo ans
