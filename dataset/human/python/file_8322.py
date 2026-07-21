import strutils,sequtils,math,algorithm
template rep(a,b):seq = newSeqWith(b,a)

proc solve(K,N:int; A:seq[int]) =
  var d=newSeq[int] N
  for i,a in A:
    d[i]=(K+A[(i+1)mod N]-a)mod K
  echo K-d.max
  

when isMainModule:
  let get = iterator:string {.closure.} = 
    for s in stdin.readAll.split: yield s
  let K,N = get().parseInt
  let A = get().parseInt.rep(N)
  solve(K,N,A)
