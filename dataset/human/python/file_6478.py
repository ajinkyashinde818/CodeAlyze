import strutils,algorithm
var
  S,q=stdin.readLine
  T= @["",S]
  d=1
for _ in 1..q.parseInt:
  q=stdin.readLine
  if q.len<2:
    d=3-d
  else:
    T[int($d != $q[2])].add $q[4]
T[d-1].reverse
echo T[d-1]&T[2-d]
