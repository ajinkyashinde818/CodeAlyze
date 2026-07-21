import sequtils, strutils, algorithm, math, future, sets, tables, hashes, intsets
let read = iterator : string {.closure.} = (while true : (for s in stdin.readLine.split : yield s))


var
   k,n = read().parseint
   a = newSeqWith(n, read().parseint)
   b = newSeq[int]()

for i in 1 ..< n: 
   b.safeadd a[i] - a[i - 1]
b.safeadd k - a[^1] + a[0]

echo k - b.max
