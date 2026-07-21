import strutils, sequtils
proc input():string = stdin.readLine

let
    li = input().split.map(parseInt)
    n = li[0]
    k = li[1]
    a = input().split.map(parseInt)

var
    cnt = 0
    r = 1
while r <= k:
    r = r shl 1
    cnt.inc

var table = newSeqWith(cnt, newSeq[int](n))
for i in 0..<cnt:
    for j in 0..<n:
        if i == 0:
            table[i][j] = a[j] - 1
        else:
            table[i][j] = table[i-1][table[i-1][j]]

var
    now = 0
    tmp = k
for i in 0..<cnt:
    if (tmp and 1) == 1:
        now = table[i][now]
    tmp = tmp shr 1

echo now + 1
