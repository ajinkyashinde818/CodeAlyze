import sequtils,strutils,algorithm
var s=newSeq[seq[string]] 2
s[0]=newSeq[string]()
s[1]=stdin.readLine.mapIt($it)
var p=1
for _ in 1..stdin.readLine.parseInt:
  let q=stdin.readLine.split
  if q[0]=="1":
    p=p xor 1
  else:
    s[int(q[1]=="1")xor p].add q[2]
(s[p xor 1].reversed&s[p]).join"".echo
