import streams, sequtils, strutils, algorithm, math, future, sets, tables, hashes
proc `ceilDiv`*[T](x, y: T): T = x div y + ord(x mod y != 0)
proc `//=`*(x: var SomeInteger; y: SomeInteger) = x = x div y
proc `%=`*(x: var SomeInteger; y: SomeInteger) = x = x mod y
var
    L = stdin.readLine.split.map(parseInt)
    N = L[0]
    M = L[1]
    A = newSeq[string](N)
    B = newSeq[string](M)
    flag = false
    cnt = 0
for i in 0..N-1:
    A[i] = stdin.readLine
for i in 0..M-1:
    B[i] = stdin.readLine
for i in 0..N-M:
    for j in 0..N-M:
        cnt = 0
        for x in 0..M-1:
            for y in 0..M-1:
                if A[i+x][j+y] == B[x][y]:
                    cnt += 1
        if cnt == M^2:
            flag = true
if flag:
    echo "Yes"
else:
    echo "No"
