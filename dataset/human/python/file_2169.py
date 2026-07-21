import sequtils, strutils, math, algorithm, tables

var
  dg = readLine(stdin).split().map(parseInt)
  d = dg[0]
  g = dg[1]
  pc :seq[seq[int]]
  res = (1 shl 29)
pc = @[]
for i in 1..d:
  var temp = readLine(stdin).split().map(parseInt)
  pc.add(temp)

for bit in 0..(1 shl d):
  var sum = 0
  var num = 0
  for i in 0..<d:
    if (bit and (1 shl i)) != 0:
      sum = sum + pc[i][1] + pc[i][0] * 100 * (i + 1)
      num = num + pc[i][0]
  if sum >= g:
    res = min(res, num)
  else:
    for i in countdown(d-1, 0):
      if (bit and (1 shl i)) != 0:
        continue
      for j in 0..<pc[i][0]:
        if sum >= g:
          break
        sum  = sum + 100 * (i + 1)
        inc(num)
    res = min(res, num)

echo res
