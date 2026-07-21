import strutils
import sequtils
import algorithm
import math
import queues
import tables
import logging
import future

const INF* = float(1e32 + 373)

when not defined(release):
  addHandler(newFileLogger(stderr, lvlAll, "[ $levelname ] "))

proc readInt1*(): int = stdin.readLine().strip().parseInt()
proc readInt2*(): (int, int) =
    let v = stdin.readLine().strip().split().map(parseInt)
    return (v[0], v[1])
proc readInt3*(): (int, int, int) =
    let v = stdin.readLine().strip().split().map(parseInt)
    return (v[0], v[1], v[2])
proc readInt4*(): (int, int, int, int) =
    let v = stdin.readLine().strip().split().map(parseInt)
    return (v[0], v[1], v[2], v[3])

proc readSeq*(): seq[string] = stdin.readLine().strip().split()
proc readSeq*(n: Natural): seq[string] =
  result = newSeq[string](n)
  for i in 0..<n:
    result[i] = stdin.readLine().strip()

type seq2*[T] = seq[seq[T]]
proc newSeq2*[T](n1, n2: Natural): seq2[T] = newSeqWith(n1, newSeq[T](n2))

#------------------------------------------------------------------------------#
# FIXME: Use object
type PriorityQueue[T] = tuple[a: seq[T], n: Natural, cmp: proc(a, b: T): bool]

proc initPriorityQueue[T](cmp: proc(a, b: T): bool): PriorityQueue[T] =
    (newSeq[T](1), Natural(0), cmp)

proc len[T](this: PriorityQueue[T]): Natural = this.n

proc enqueue[T](this: var PriorityQueue[T], e: T) =
    this.n += 1
    this.a.add(e)
    var i = this.a.len() - 1
    while i > 1 and this.cmp(this.a[i], this.a[i div 2]):
        swap(this.a[i], this.a[i div 2])
        i = i div 2

proc dequeue[T](this: var PriorityQueue[T]): T =
    this.n -= 1
    result = this.a[1]
    this.a[1] = this.a.pop()
    var i = 1
    while i < this.a.len():
        var j = i
        if i * 2 < this.a.len() and this.cmp(this.a[i * 2], this.a[j]):
            j = i * 2
        if i * 2 + 1 < this.a.len() and this.cmp(this.a[i * 2 + 1], this.a[j]):
            j = i * 2 + 1
        if i == j:
            break
        swap(this.a[i], this.a[j])
        i = j

# FIXME: throw Exception when this is empty
proc front[T](this: PriorityQueue[T]): T = this.a[1]

type Circle = tuple[y, x, r: float]

proc distance(c1, c2: Circle): float =
  var dy = c1.y - c2.y
  var dx = c1.x - c2.x
  var d = sqrt(dy * dy + dx * dx)
  return max(d - c1.r - c2.r, 0.0)

proc dijkstra(n: int, g: seq2[float], s: int): seq[float] =
  var d = newSeq[float](n)
  d.fill(INF)
  d[s] = 0.0

  type P = tuple[c: float, v: int]
  var q = initPriorityQueue[P]((p1: P, p2: P) => p1.c < p2.c)
  q.enqueue((0.0, s))

  while q.len() > 0:
    let (c, v) = q.dequeue()
    if c > d[v]:
      continue
    for u in 0..<n:
      let alt = d[v] + g[v][u]
      if alt < d[u]:
        d[u] = alt
        q.enqueue((alt, u))

  return d

proc main() =
  let (xs, ys, xt, yt) = readInt4()
  let n = readInt1()

  var cs = newSeq[Circle](n + 2)
  for i in 0..<n:
    let (x, y, r) = readInt3()
    cs[i] = (float(y), float(x), float(r))

  cs[n] = (float(ys), float(xs), 0.0)
  cs[n + 1] = (float(yt), float(xt), 0.0)

  var g = newSeq2[float](n + 2, n + 2)

  for i in 0..<n + 2:
    for j in 0..<n + 2:
      g[i][j] = distance(cs[i], cs[j])

  let d = dijkstra(n + 2, g, n)
  echo d[n + 1]

main()
