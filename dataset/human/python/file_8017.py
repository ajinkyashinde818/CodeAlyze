import strutils,sequtils
let
 ks=stdin.readline.split.map(parseInt)
 (k,s)=(ks[0],ks[1])
var count=0
for i in 0..k:
 for j in 0..i:
  for k in 0..j:
   if i+j+k==s:
    if i==j and j==k:
     count+=1
    elif i!=j and j!=k and k!=i:
     count+=6
    else:
     count+=3
echo count
