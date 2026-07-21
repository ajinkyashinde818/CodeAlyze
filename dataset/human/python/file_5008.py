import sequtils, strutils, algorithm, math, future, sets, tables, hashes, intsets
let read = iterator : string {.closure.} = (while true : (for s in stdin.readLine.split : yield s))

proc bfs(cur : var seq[int], adj : seq[seq[int]], dist, n : int) = 
   var next : seq[int]

   if dist == 2 : 
      if n - 1 in cur : 
         echo "POSSIBLE"
      else : 
         echo "IMPOSSIBLE"
      return

   for val in cur : 
      for dest in adj[val] : 
         next.safeadd dest
   cur = @[]
   bfs(next, adj, dist + 1, n)

proc solve() =
   
   var
      n, m = read().parseInt
      adj = newSeqWith(n, newSeq[int]())
      Q : seq[int]
      

   for i in 0 ..< m : 
      var a, b = read().parseInt - 1
      adj[a].safeadd b
      adj[b].safeadd a

   Q.safeadd 0
   bfs(Q, adj, 0, n)

solve()
