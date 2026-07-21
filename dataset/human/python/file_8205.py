import sequtils,strutils,sets
var
    f : int
    s = stdin.readline
    cnt : int
    cnts = newSeqWith(2, newSeq[int](0))
    F : array[2, bool]
    P = stdin.readline.split.map(parseInt)
    x : int

s = s & "T"
for c in s:
    if c == 'T':
        cnts[(f and 1)].add(cnt)
        f += 1
        cnt = 0
    elif c == 'F':
        cnt += 1
x = cnts[0][0]
for d in 0..1:
    var
        S = initSet[int](16384)
        S2 = S
    if d == 1:
        S.incl(0)
    else:
        S.incl(x)
    for p,k in cnts[d]:
        if d == 0 and p == 0:
            continue
        for i in S:
            S2.incl(i + k)
            S2.incl(i - k)
        S = S2
        S2.init
    if S.contains(P[d]):
        F[d] = true
if F[0] and F[1]:
    echo "Yes"
else:
    echo "No"
