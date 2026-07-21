from strutils import split, parseInt
from sequtils import map

let
  ks = stdin.readLine.split.map(parseInt)
  (k, s) = (ks[0], ks[1])

var count = 0
for x in 0..k:
  for y in 0..k:
    let z = s - x - y
    if 0 <= z and z <= k:
      count.inc

echo count
