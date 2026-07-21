import sequtils,strutils

var
  nm = readLine(stdin).split().map(parseInt)
  n = nm[0]
  m = nm[1]
  ab: seq[string]
  a: seq[string]
  b: seq[string]
  cnt = 0
ab = @[]
for i in 0..<n+m:
  ab.add(readLine(stdin))

a = ab[0..<n]
b = ab[n..<n+m]

for i in 0..n-m:
  for j in 0..n-m:
    if map(a[i..i+m-1], proc(x: string): string = x[j..j+m-1]) == b:
      cnt = cnt + 1
if cnt > 0:
  echo "Yes"
else:
  echo "No"
