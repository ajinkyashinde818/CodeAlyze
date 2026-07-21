import strutils, sequtils

const MOD = 1_000_000_007

proc `*=`(a: var int; b: int) = a = a * b mod MOD

let
  N = stdin.readLine.parseInt
  S = stdin.readLine

var counts: array['a'..'z', int]
for c in S:
  counts[c].inc

var result = 1
for count in counts:
  result *= count + 1

echo result - 1
