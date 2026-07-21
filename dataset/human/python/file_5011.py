import sequtils, strutils, algorithm, math, future, sets, tables, hashes
proc `ceilDiv`*[T](x, y: T): T = x div y + ord(x mod y != 0)
proc `//=`*(x: var SomeInteger; y: SomeInteger) = x = x div y
proc `%=`*(x: var SomeInteger; y: SomeInteger) = x = x mod y
var
    N, M:int
    a, b:int
    d = initTable[int, seq[int]]()
    flag = false
(N, M) = stdin.readLine.split.map(parseInt)
for i in 0..M-1:
    (a, b) = stdin.readLine.split.map(parseInt)
    if not d.hasKey(b):
        d[b] = @[a]
    else:
        d[b].add a
    if not d.hasKey(a):
        d[a] = @[b]
    else:
        d[a].add b
for k in d[1]:
    if N in d[k]:
        flag = true
if flag:
    echo "POSSIBLE"
else:
    echo "IMPOSSIBLE"
