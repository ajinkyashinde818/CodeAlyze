import  macros, algorithm, tables, sets, lists,intsets, critbits, sequtils, strutils, math, future
proc readSeq(): seq[string] =
    stdin.readLine.split
proc readInt1(): int =
    stdin.readLine.parseInt
proc readInt2(): (int, int) =
    let a = readSeq().map(parseInt)
    return (a[0], a[1])
proc readInt3(): (int, int, int) =
    let a = readSeq().map(parseInt)
    return (a[0], a[1], a[2])
proc readInt4(): (int, int, int, int) =
    let a = readSeq().map(parseInt)
    return (a[0], a[1], a[2], a[3])



var S= stdin.readLine.mapIt(($it).parseInt)
S.reverse
S.add(0)
S.add(0)
var cost=0

for i in 0..<( S.len-1 ):

    if S[i]>=6 or (S[i]==5 and S[i+1]>=5):
        S[i]=10-S[i]
        S[i+1]+=1
    cost+=S[i]
echo cost+S[S.len-1]
