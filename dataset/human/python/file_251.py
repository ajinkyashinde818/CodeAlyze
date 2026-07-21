import algorithm,tables,hashes,math
import sets,lists,critbits,sequtils,queues,intsets,strutils
 
let N = stdin.readline().parseInt
let a:seq[int] = map(stdin.readline().split(" "),parseInt)

var minimum:int = 999999999
var count = 0
var sum = 0
for i in 0..N-1:
 minimum = min(minimum,abs(a[i]))
 if a[i] < 0:
  count += 1
 sum += abs(a[i])
if count mod 2 == 0:
 echo sum
else:
 echo (sum - 2*minimum)
