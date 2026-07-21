import strutils, sequtils
var N, K: int; (N, K) = stdin.readLine.split.map parseInt
let As = stdin.readLine.split.mapIt(it.parseInt - 1)
var vs, ts = (-1).repeat(N + 1)
vs[0] = 0; ts[0] = 0
for i in 1 .. N:
  let next = As[vs[i - 1]]
  if ts[next] >= 0:
    let m = i - ts[next]
    echo vs[ts[next] + (K - ts[next]) mod m] + 1; quit()
  if i == K: echo next + 1; quit()
  ts[next] = i
  vs[i] = next
