import strutils
import sequtils
import algorithm
import math
import queues
import tables
import logging
import future

const INF* = int(1e18 + 373)

when not defined(release):
  addHandler(newFileLogger(stderr, lvlAll, "[ $levelname ] "))

proc readInt1*(): int = stdin.readLine().strip().parseInt()
proc readInt2*(): (int, int) =
    let v = stdin.readLine().strip().split().map(parseInt)
    return (v[0], v[1])
proc readInt3*(): (int, int, int) =
    let v = stdin.readLine().strip().split().map(parseInt)
    return (v[0], v[1], v[2])

proc readSeq*(): seq[string] = stdin.readLine().strip().split()
proc readSeq*(n: Natural): seq[string] =
  result = newSeq[string](n)
  for i in 0..<n:
    result[i] = stdin.readLine().strip()

type seq2*[T] = seq[seq[T]]
proc newSeq2*[T](n1, n2: Natural): seq2[T] = newSeqWith(n1, newSeq[T](n2))

#------------------------------------------------------------------------------#
# proc build(s: seq[string]; v, d: int; g: var seq2[int]) =
#   for c in @['0', '1']:
#     let t = s.filter(it => it.len() > d and it[d] == c)
#     if t.len() > 0:
#       let u = g.len()
#       g.add(@[])
#       g[v].add(u)
#       build(t, u, d + 1, g)
proc append(g: var seq2[int]; v, d: int; s: string) =
  if s.len() <= d:
    return

  let c = s[d].ord() - '0'.ord()
  if g[v][c] == -1:
    let u = g.len()
    g.add(@[-1, -1])
    g[v][c] = u

  append(g, g[v][c], d + 1, s)

proc dfs(n: int; g: seq2[int]; v, d, h: int; ts: var seq[int]) =
  if g[v].filter(it => it == -1).len() == 1:
    ts.add(h - d)

  for u in g[v]:
    if u == -1:
      continue
    dfs(n, g, u, d + 1, h, ts)

proc grundy(n: int): int =
  var m = n
  var i = 1
  while m mod 2 == 0:
    m = m div 2
    i += 1
  return i

proc main() =
  let (n, h) = readInt2()
  let s = readSeq(n)

  var g = newSeq2[int](1, 0)
  g[0] = @[-1, -1]
  # build(s, 0, 0, g)
  for i in 0..<n:
    append(g, 0, 0, s[i])
  let m = g.len()

  #echo g

  var ts = newSeq[int](0)
  dfs(n, g, 0, 0, h, ts)

  var ans = 0
  for t in ts:
    ans = ans xor grundy(t)

  echo if ans == 0: "Bob" else: "Alice"

main()
