import sequtils, strutils, math, algorithm

var
  n = parseInt(readLine(stdin))
  a = readLine(stdin).split().map(parseInt)
  ans = 10^10 + 7
  a_sum = a.sum()
  array = 0

for i in 0..<n-1:
  array = array + a[i]
  if ans > abs(2 * array - a_sum):
    ans = abs(2 * array - a_sum)

echo ans
