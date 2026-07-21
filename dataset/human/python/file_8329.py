import strutils,sequtils

var
    opt = stdin.readLine.split.map(parseInt)
    K = opt[0]
    N = opt[1]
    A = stdin.readLine.split.map(parseInt)
    r :seq[int]
newSeq(r,N)
for i in 1..N-1:
    r.add(A[i]-A[i-1])
r.add(A[0]+K-A[N-1])
r.add(-max(r))
echo r.foldl(a+b)
