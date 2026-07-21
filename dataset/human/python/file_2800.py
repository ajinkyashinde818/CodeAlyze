import sequtils, strutils, strformat, algorithm, math, sugar,tables,heapqueue
{.warning[UnusedImport]:off.}
proc scanf(fmt: cstring){.header: "<stdio.h>", varargs.}
proc inp:int{.used.} = scanf("%lld", addr result)
template newSeqWith(y, x: int, p: untyped):untyped{.used.}= newSeqWith(y, newSeqWith(x, p))

proc getPrimes(num:int):CountTable[int]=
  var tb = initCountTable[int]()

  var b = num
  for p in 2..b:
    if p * p > b: break
    if b mod p == 0:
      var e = 0
      while b mod p == 0:
        e += 1
        b = b div p
      tb[p] = e
  if b > 1: tb[b] = 1
  return tb

var N = inp()
var tbl = getPrimes(N)
var ans = 0

for key,value in tbl:
  var v = value
  var cnt = 1
  while v>=cnt:
    v -= cnt
    cnt += 1
    ans += 1

echo ans
