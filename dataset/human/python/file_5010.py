import strutils,sequtils,future
let
 nm=stdin.readline.split.map(parseInt)
 (n,m)=(nm[0],nm[1])
var
 fi:seq[int]= @[] 
 se=repeat(0,n)
for i in 1..m:
 let ab=stdin.readline.split.map(parseInt)
 if ab[0]==1:
  fi.add(ab[1]-1)
 elif ab[1]==n:
  se[ab[0]-1]=1
for i in fi:
 if se[i]==1:
  echo "POSSIBLE"
  quit()
echo "IMPOSSIBLE"
