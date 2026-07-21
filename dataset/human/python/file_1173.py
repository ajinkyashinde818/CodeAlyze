import strutils,sequtils,math
let 
 n=stdin.readline.parseInt
 a=stdin.readline.split.map(parseInt)
 su=a.sum
var
 dev=su-2*a[0]
 midev=abs(su-2*a[0])
for i in a[1..^2]:
 dev-=2*i
 midev=min(midev,abs(dev))
echo midev
