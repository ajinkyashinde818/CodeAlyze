import sequtils, strutils, algorithm, math
proc scanf(fmt: cstring){.header: "<stdio.h>", varargs.}
proc scan(): int = scanf("%lld", addr result)
when (NimMajor, NimMinor) <= (0, 18): import future else: import sugar

let S = stdin.readLine()
let Q = stdin.readLine.parseInt()

const MX = 10^5
const Z = MX * 2
var DQ = repeat(' ', MX * 5)
for i in 0..<S.len: DQ[Z+i] = S[i]
var p = [Z-1, Z+S.len]
var rev = false

for i in 0..<Q:
  #dump(DQ[p[0]+1..p[1]-1])
  let query = stdin.readLine().split()
  if query[0] == "1":
    rev = not rev
  else:
    var pos = p[0]
    if ((not rev) and (query[1] == "2")) or ((rev) and (query[1] == "1")):
      DQ[p[1]] = query[2][0]
      p[1] += 1
    else:
      DQ[p[0]] = query[2][0]
      p[0] -= 1

var ans = repeat(' ', p[1]-p[0]-1)

var idx = 0
for i in (p[0]+1)..<p[1]:
  ans[idx] = DQ[i]
  idx += 1

if rev: ans.reverse()

echo($ans)
