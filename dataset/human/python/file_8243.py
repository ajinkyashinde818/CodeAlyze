import strutils,sequtils,math,algorithm,future
template rep(a,b):seq = newSeqWith(b,a)
let yesno = (p: bool) => (if p: "YES" else: "NO")

proc solve(N:int; A:seq[int]) =
  let s = A.sum
  if s mod (N*(N+1) div 2) != 0:
    echo yesno false; return
  let k = s div (N*(N+1) div 2)
  let a = A & A[0]
  let d = toSeq(1..N).mapIt(a[it]-a[it-1]-k)
  echo yesno d.allIt(it mod N == 0 and it <= 0) and d.sum == -k*N

when isMainModule:
  let get = iterator:string {.closure.} = 
    for s in stdin.readAll.split: yield s
  let N = get().parseInt
  let A = get().parseInt.rep(N)
  solve(N,A)
