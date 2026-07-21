import streams, sequtils, strutils, algorithm, math, future, sets, tables, hashes
proc `ceilDiv`*[T](x, y: T): T = x div y + ord(x mod y != 0)
proc `//=`*(x: var SomeInteger; y: SomeInteger) = x = x div y
proc `%=`*(x: var SomeInteger; y: SomeInteger) = x = x mod y

var
    L = stdin.readLine.split.map(parseInt)
    N = L[0]
    K = L[1]
    A = stdin.readLine.split.map(parseInt)
    route = newSeq[int]()
    state = 0
    visited = newSeqWith(N, false)
visited[0] = true
route.add state
while true:
    state = A[state] - 1
    route.add state
    if visited[state]:
        break
    visited[state] = true

if route.len > K:
    echo route[K] + 1
else:
    var
        idx = 0
        cnts = newSeqWith(N, 0)
        ans:int
    for i in 0..route.len-1:
        cnts[route[i]] += 1
    for i in 0..N-1:
        if cnts[i] == 2:
            idx = route.find(i)
            break
    K -= idx
    ans = route[idx..^2][K mod route[idx..^2].len] + 1
    echo ans
