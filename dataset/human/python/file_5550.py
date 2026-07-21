import sequtils,strutils,math
var
    s = stdin.readline
    A = newSeq[char](0)
    Cnts = newSeq[int](0)
var cnt : int
for c in s:
    if c != 'x':
        A.add(c)
        Cnts.add(cnt)
        cnt = 0
    else:
        cnt += 1
Cnts.add(cnt)
        
block solve:
    for i in 0..(A.high div 2):
        if A[i] != A[A.high - i]:
            echo -1
            break solve
    cnt = 0
    for i in 0..(Cnts.high div 2):
        cnt += abs(Cnts[i] - Cnts[Cnts.high - i])
    echo cnt
