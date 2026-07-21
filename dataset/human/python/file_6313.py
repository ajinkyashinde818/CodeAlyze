import streams, queues, sequtils, strutils, algorithm, math, future, sets, tables, hashes
proc `ceilDiv`*[T](x, y: T): T = x div y + ord(x mod y != 0)
proc `//=`*(x: var SomeInteger; y: SomeInteger) = x = x div y
proc `%=`*(x: var SomeInteger; y: SomeInteger) = x = x mod y

var 
    N = stdin.readLine.parseInt
    cnt = 0
if N mod 2 == 1:
    cnt = 0
else:
    cnt += N div 10
    N //= 10
    while N > 0:
        cnt += N div 5
        N //= 5
echo cnt
