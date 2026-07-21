import sequtils, strutils, algorithm, math, future, sets, tables, hashes, intsets
let read = iterator : string {.closure.} = (while true : (for s in stdin.readLine.split : yield s))



proc solve() =
   
   var
      n,r = read().parseInt

   if n >= 10 : 
      echo r
   else : 
      echo r + 100 * (10 - n)

solve()
