import algorithm, future, macros, math, sequtils, sets, strutils, tables

macro unpack(rhs: seq, cnt: static[int]): auto =
  let t = genSym(); result = quote do:(let `t` = `rhs`;())
  if NimMinor <= 17:
    for i in 0..<cnt: result[0][1].add(quote do:`t`[`i`])
  else:
    for i in 0..<cnt: result[1].add(quote do:`t`[`i`])

template input(T: typedesc, cnt: Natural = 1): untyped =
  let line = stdin.readLine.split(" ")
  when T is int:         line.map(parseInt).unpack(cnt)
  elif T is float:       line.map(parseFloat).unpack(cnt)
  elif T is string:      line.unpack(cnt)
  elif T is char:        line.mapIt(it[0]).unpack(cnt)
  elif T is seq[int]:    line.map(parseint)
  elif T is seq[float]:  line.map(parseFloat)
  elif T is seq[string]: line
  elif T is seq[char]:   line.mapIt(it[0])

proc `&=`(n: var int, m: int) = n = n and m
proc `|=`(n: var int, m: int) = n = n or m
proc `%=`(n: var int, m: int) = n = n mod m
proc `//=`(n: var int, m: int) = n = n div m
proc `<<=`(n: var int, m: int) = n = n shl m
proc `>>=`(n: var int, m: int) = n = n shr m
proc `<?=`(n: var SomeNumber, m: SomeNumber) = n = min(n, m)
proc `>?=`(n: var SomeNumber, m: SomeNumber) = n = max(n, m)
proc newSeq2[T](n1, n2: Natural): seq[seq[T]] = newSeqWith(n1, newSeq[T](n2))
proc newSeq3[T](n1, n2, n3: Natural): seq[seq[seq[T]]] = newSeqWith(n1, newSeqWith(n2, newSeq[T](n3)))

# -------------------------------------------------- #

type PriorityQueue[T] = object
  a: seq[T]
  n: Natural
  cmp: (a: T, b: T) -> bool
 
proc initPriorityQueue[T](cmp: (a: T, b: T) -> bool): PriorityQueue[T] =
  result.a = newSeq[T](1)
  result.n = Natural(0)
  result.cmp = cmp
 
proc len[T](this: PriorityQueue[T]): Natural =
  this.n
 
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
 
proc front[T](this: PriorityQueue[T]): T =
  this.a[1]

# -------------------------------------------------- #

const INF = 1e12

type P = tuple[v: int, c: float]
type Edge = tuple[to: int, cost: float]
proc dijkstra(N: int, s: int, G: seq[seq[Edge]]): seq[float] =
  var que = initPriorityQueue[P]((p1: P, p2: P) => p1.c < p2.c)
  var d = newSeqWith(N + 1, INF)
  d[s] = 0.0
  que.enqueue((s, 0.0))

  while que.len > 0:
    var (v, dist) = que.dequeue()
    if d[v] < dist:
      continue
    for data in G[v]:
      var u = data.to
      var c = data.cost
      if d[u] > d[v] + c:
        d[u] = d[v] + c
        que.enqueue((u, d[u]))
  return d

# -------------------------------------------------- #

var (xs, ys, xt, yt) = input(float, 4)
var N = input(int)
var circle = newseq[tuple[x: float, y: float, r: float]](N + 2)
for i in 1 .. N:
  circle[i] = input(float, 3)
circle[0] = (xs, ys, 0.0)
circle[N + 1] = (xt, yt, 0.0)
var edge = newseq2[Edge](N + 2, 0)
for i in 0 .. N:
  for j in i + 1 .. N + 1:
    var (x1, y1, r1, x2, y2, r2) = (circle[i].x, circle[i].y, circle[i].r, circle[j].x, circle[j].y, circle[j].r)
    var cost = max(0.0, sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) - (r1 + r2))
    edge[i].add((j, cost))
    edge[j].add((i, cost))
var d = dijkstra(N + 1, 0, edge)
echo d[N + 1]
