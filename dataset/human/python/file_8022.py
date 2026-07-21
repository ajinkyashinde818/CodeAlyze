import strutils, sequtils
let KS = stdin.readline.split.map(parseInt)
let (K, S) = (KS[0], KS[1])
var cnt = 0
for x in 0 .. K:
  if x > S: break
  if x < S - 2 * K: continue
  for y in 0 .. K:
    if x + y > S: break
    if x + y < S - K: continue
    cnt += 1
echo cnt
