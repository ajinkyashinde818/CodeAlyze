import sequtils, strutils, algorithm, math, sets, tables
when NimMajor == 0 and NimMinor <= 18: import future else: import sugar

var N = stdin.readline.parseInt

if N mod 2 == 1:
  echo 0
  quit 0

var zero = 0
for i in 1..25:
  let t = (5^i)*2
  #dump(t)
  zero += N div t

echo zero
