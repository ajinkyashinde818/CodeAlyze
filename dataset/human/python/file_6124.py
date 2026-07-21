import sequtils, strutils, algorithm, math, future, sets, tables, hashes

let read = iterator : string {.closure.} = (while true : (for s in stdin.readLine.split : yield s))


proc solve() =
   
   var
      a,b,c = read().parseInt
      
   echo b + min((a + b) + 1, c)

solve()
