import sequtils, strutils, algorithm, math, future, sets, tables, hashes

proc solve() =
   
   var s,t = stdin.readLine
   s.sort(system.cmp[char])
   t.sort(system.cmp[char])
   t.reverse
   if s < t : 
      echo "Yes"
   else : 
      echo "No"

solve()
