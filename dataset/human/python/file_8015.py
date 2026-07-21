import sequtils, strutils, algorithm, math, future, sets, tables, hashes

proc solve() =

  var k,s : int
  (k,s) = stdin.readLine.split.map(parseInt)

  var ans = 0
  for x in 0 .. k : 
    for y in 0 .. k : 
      var z = s - x - y
      if z <= k and z >= 0 : 
          ans += 1
  echo ans 


solve()
