import sequtils, strutils, strformat, algorithm, math, sugar,tables
{.warning[UnusedImport]:off.}
proc scanf(fmt: cstring){.header: "<stdio.h>", varargs.}
proc inp:int{.used.} = scanf("%lld", addr result)
template newSeqWith(y, x: int, p: untyped):untyped{.used.}= newSeqWith(y, newSeqWith(x, p))

var N,K = inp()
var A = newSeqWith(N,inp()-1)
var CNT = newSeqWith(N+1,-1)
var TUKA = newSeqWith(N+1,-1)
CNT[0] = 0
TUKA[0] = 0

var now = 0
for i in 1..min(K,N):

  now = A[now]
  CNT[i] = now

  if (K) == i:
    echo(now+1)
    quit()

  #dump(CNT)

  if TUKA[now] != -1:
    let st = TUKA[now]
    let loop = i - st
    K -= st
    #dump(K)
    #dump(K mod loop)
    echo(CNT[(K mod loop)+st]+1)
    quit()
  else:
    TUKA[now] = i
