import strutils,sequtils,algorithm
var 
 s=stdin.readline
 count=0
 add1=""
 add2=""
let q=stdin.readline.parseInt
for i in 1..q:
 var qu=stdin.readline
 if qu[0]=='1':
  count+=1
 else:
  var q2=qu.split
  if (count mod 2==0 and q2[1]=="2") or (count mod 2==1 and q2[1]=="1"):
   add1&=q2[2]
  else:
   add2&=q2[2]
if count mod 2==1:
 for i in (s&add1).reversed:
  stdout.write(i) 
 stdout.write(add2)
else:
 for i in add2.reversed:
  stdout.write(i)
 stdout.write(s&add1)
