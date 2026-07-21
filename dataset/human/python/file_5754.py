import strutils,sequtils
let
  n=stdin.readline.parseInt
  a,b,c=stdin.readline.split.map(parseInt)
var
  count=0
for k,i in a:
  if a[k+1]==i+1:
    count+=b[i-1]+c[i-1]
  else:
    count+=b[i-1]
echo count
