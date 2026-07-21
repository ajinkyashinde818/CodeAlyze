import sequtils, strutils, algorithm, math, future, sets, tables, hashes

proc solve() =
   
   var s = stdin.readLine
   var q = stdin.readLine.parseInt
   var flip = false
   var matubi, sentou : seq[char]
   for i in 0 ..< q : 
      var line = stdin.readLine
      if line == "1" : 
         flip = (flip xor true)
      else : 
         var num, f , c : char
         (num, f, c) = line.split.map(x => x[0])
         var matu = (f == '2')
         if matu xor flip : 
            matubi.safeadd(c)
         else : 
            sentou.safeadd(c)
   if flip : 
      for i in countdown(matubi.high, matubi.low) : 
         stdout.write matubi[i]
      for i in  countdown(s.high, s.low) : 
         stdout.write s[i]
      for i in sentou.low .. sentou.high : 
         stdout.write sentou[i]
      echo ""
   else : 
      for i in countdown(sentou.high, sentou.low) : 
         stdout.write sentou[i]
      stdout.write s
      for i in matubi.low .. matubi.high : 
         stdout.write matubi[i]
      echo ""

solve()
