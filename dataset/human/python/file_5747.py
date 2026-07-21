import sequtils, strutils, algorithm, math, future, sets, tables, hashes

let read = iterator : string {.closure.} = (while true : (for s in stdin.readLine.split : yield s))


proc solve() =
   
   var
      n = read().parseInt
      a,b,c = stdin.readLine.split.map(parseInt)
      sum = 0
   
   sum += b[a[0] - 1]
   for i in 1 ..< n : 
      sum += b[a[i] - 1]
      if a[i] - 1 == a[i - 1] : 
         sum += c[a[i - 1] - 1]
   echo sum

solve()
