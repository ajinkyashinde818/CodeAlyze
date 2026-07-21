import sequtils, strutils, math, algorithm

var
  nm = readLine(stdin).split().map(parseInt)
  ab: seq[seq[int]]
  first: seq[int]
  last: seq[int]
first = @[]
last = @[]

for i in 0..<nm[1]:
  var temp = readLine(stdin).split().map(parseInt)
  if temp[0] == 1:
    first.add(temp[1])
  elif temp[1] == nm[0]:
    last.add(temp[0])
last = last.sorted(system.cmp[int])
for f in first:
  if binarySearch(last, f) > -1:
    echo "POSSIBLE"
    quit()
echo "IMPOSSIBLE"
