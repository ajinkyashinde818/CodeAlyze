import sequtils, strutils, algorithm, math, future, sets, tables, hashes
proc `ceilDiv`*[T](x, y: T): T = x div y + ord(x mod y != 0)
proc `//=`*(x: var SomeInteger; y: SomeInteger) = x = x div y
proc `%=`*(x: var SomeInteger; y: SomeInteger) = x = x mod y

var
    K, S:int
    ans = 0
    z:int
(K, S) = stdin.readLine.split.map(parseInt)
for x in 0..K:
    for y in 0..K:
        z = S - x - y
        if z >= 0 and z <= K:
            inc ans
echo ans
