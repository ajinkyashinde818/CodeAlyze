import sequtils,strutils
var
    N = stdin.readline.parseBiggestInt
    P = newSeq[array[2,int]](0)
    ans : int

for i in 2..1000010:
    if i * i > N:
        break
    while N mod i.int64 == 0:
        if P.len > 0 and P[^1][0] == i:
            P[^1][1] += 1
        else:
            P.add([i, 1])
        N = N div i.int64
if N > 1:
    P.add([1, 1])

for p in P:
    var i : int = 1
    while (i + 1) * (i + 2) div 2 <= p[1]:
        i += 1
    ans += i
echo ans
