import sequtils, strutils, algorithm, math, future, sets, tables, hashes

let read = iterator : string {.closure.} = (while true : (for s in stdin.readLine.split : yield s))


proc solve() =
   
   var tab = initTable[char, int]()

   var
      n = read().parseInt
      s = read()
   let MOD = 10 ^ 9 + 7
   

   for c in 'a' .. 'z' : 
      tab[c] = 0
   
   for c in s : 
      tab[c] += 1

   var ans = 1

   for c in 'a' .. 'z' : 
      if tab[c] == 0 : 
         continue
      ans = ans * (tab[c] + 1) mod MOD
   
   echo ans - 1
   

solve()
