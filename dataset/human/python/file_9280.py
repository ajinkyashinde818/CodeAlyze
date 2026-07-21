import strutils,sequtils
proc parsed(x:string):int=
 return x.parseInt-1
let
 nk=stdin.readline.split.map(parseInt)
 (n,k)=(nk[0],nk[1])
 a=stdin.readline.split.map(parsed)
var
 num=1
 pos=a[0]
 loop:seq[int]
 yet=repeat(true,n)
 whe=repeat(0,n)
loop.add(0)
yet[0]=false
while yet[pos]:
 loop.add(pos)
 yet[pos]=false
 whe[pos]=num
 pos=a[pos]
 num+=1
if k<loop.len:
 echo loop[k]+1
else:
 echo loop[(k-whe[pos]) mod (num-whe[pos])+whe[pos]]+1
