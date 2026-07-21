import macros
import algorithm
import tables
import sets
import lists
import queues
import intsets
import critbits
import sequtils
import strutils
import math
import future

var
  D, G: int
  P, C = newSeq[int]()

(D, G) = stdin.readLine.split.map(parseInt)
for i in 0..<D:
  var p, c: int
  (p, c) = stdin.readLine.split.map(parseInt)
  P.add(p)
  C.add(c)

var ans = P.sum

for i in 0..<2^D:
  var
    cnt = 0
    pnt = 0
  for j in 0..<D:
    if ((i shr j) mod 2) == 1:
      cnt += P[j]
      pnt += 100*(j+1)*P[j] + C[j]
  if pnt >= G:
    ans = min(ans, cnt)
    continue
  for j in countdown(D-1, 0):
    if ((i shr j) mod 2) == 0:
      var tmp = (G - pnt + 100*(j+1) - 1) div (100*(j+1))
      if tmp > P[j]:
        break
      ans = min(ans, cnt + tmp)
      break

echo ans
