import strutils
import sequtils
 
proc getInts() : seq[int] = 
  readLine(stdin).split().map(parseInt)
    
var arr = getInts()
var a = arr[0]
var b = arr[1]
var ans = 0
 
for x in 0..a:
  for y in 0..a:
     let z = b - x - y
     
     if (z >= 0 and a >= z):
       ans += 1
 
echo ans
