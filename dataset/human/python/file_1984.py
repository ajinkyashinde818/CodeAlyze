import lists, sequtils, strutils, algorithm, math, future, tables

var N = stdin.readLine.parseInt
var S = stdin.readLine

var tb = initCountTable[char]()

for x in S:
    tb.inc(x)

var re = 1

for x,c in tb:
    re = (re*(c+1)) mod (1000000007)

re = (re-1) mod (1000000007)

echo re
