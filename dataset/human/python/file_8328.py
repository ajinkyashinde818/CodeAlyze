import strutils,sequtils
let
 kn=stdin.readline.split.map(parseInt)
 (k,n)=(kn[0],kn[1])
 a=stdin.readline.split.map(parseInt)
var
 cut=repeat(0,n)
for j,i in a:
 if j==0:
  cut[j]=a[n-1]-i
 else:
  cut[j]=a[j-1]+k-i
echo cut.min
