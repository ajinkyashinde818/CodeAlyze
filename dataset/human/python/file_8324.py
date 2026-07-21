import sequtils, strutils, algorithm, math
proc scanf(fmt: cstring){.header: "<stdio.h>", varargs.}
proc scan(): int = scanf("%lld", addr result)
when (NimMajor, NimMinor) <= (0, 18): import future else: import sugar
template newSeqWith(y, x: int, p: untyped): untyped = newSeqWith(y, newSeqWith(x, p))

let K,N = scan()
var A = newSeqWith(N,scan())
A.add(K+A[0])

var total = 0
var mx = 0
for i in 0..<N:
  let a = A[i+1]-A[i]
  mx = max(mx,a)
  total += a 

echo(total-mx)
