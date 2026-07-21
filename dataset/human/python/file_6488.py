import algorithm, complex, macros, math, sequtils, sets, strutils, tables, times
when NimMajor == 0 and NimMinor <= 19:
  import future
else:
  import sugar, strformat

macro unpack*(rhs: seq, cnt: static[int]): auto =
  let v = genSym(); result = quote do:(let `v` = `rhs`;())
  when NimMajor == 0 and NimMinor <= 17:
    for i in 0 ..< cnt: result[0][1].add(quote do:`v`[`i`])
  else:
    for i in 0 ..< cnt: result[1].add(quote do:`v`[`i`])

template input*(T: typedesc, cnt: Natural = 1): untyped =
  let line = stdin.readLine.split(" ")
  when T is int:         line.map(parseInt).unpack(cnt)
  elif T is float:       line.map(parseFloat).unpack(cnt)
  elif T is string:      line.unpack(cnt)
  elif T is char:        line.mapIt(it[0]).unpack(cnt)
  elif T is seq[int]:    line.map(parseInt)
  elif T is seq[float]:  line.map(parseFloat)
  elif T is seq[string]: line
  elif T is seq[char]:   line.mapIt(it[0])

macro dump*(arg: varargs[untyped]): untyped =
  result = newNimNode(nnkStmtList)
  for x in arg:
    let name = toStrLit(x)
    result.add(quote do: stderr.write `name`, " = " , `x`, "\n")

proc `|=`*(n: var int, m: int) = n = n or m
proc `|=`*(n: var bool, m: bool) = n = n or m
proc `&=`*(n: var int, m: int) = n = n and m
proc `&=`*(n: var bool, m: bool) = n = n and m
proc `^=`*(n: var int, m: int) = n = n xor m
proc `^=`*(n: var bool, m: bool) = n = n xor m
proc `%=`*(n: var int, m: int) = n = n mod m
proc `/=`*(n: var int, m: int) = n = n div m
proc `<<=`*(n: var int, m: int) = n = n shl m
proc `>>=`*(n: var int, m: int) = n = n shr m
proc `<?=`*(n: var SomeNumber, m: SomeNumber) = n = min(n, m)
proc `>?=`*(n: var SomeNumber, m: SomeNumber) = n = max(n, m)
proc newSeq2*[T](n1, n2: Natural): seq[seq[T]] = newSeqWith(n1, newSeq[T](n2))
proc newSeq3*[T](n1, n2, n3: Natural): seq[seq[seq[T]]] = newSeqWith(n1, newSeqWith(n2, newSeq[T](n3)))
proc newSeq4*[T](n1, n2, n3, n4: Natural): seq[seq[seq[seq[T]]]] = newSeqWith(n1, newSeqWith(n2, newSeqWith(n3, newSeq[T](n4))))

# -------------------------------------------------- #

type
  Deque[T] = object
    data: seq[T]
    mask, head, tail, count: int

proc initDeque*[T](initialSize: int = 4): Deque[T] =
  result.data = newSeq[T](initialSize.nextPowerOfTwo)
  result.mask = initialSize.nextPowerOfTwo - 1
  result.head = 0
  result.tail = 0
  result.count = 0
  
proc len*[T](deq: Deque[T]): int =
  result = deq.count

template emptyCheck*(deq) =
  when compileOption("boundChecks"):
    if unlikely(deq.count < 1):
      raise newException(IndexError, "Empty deque.")

iterator pairs*[T](deq: Deque[T]): tuple[key: int, val: T] =
  var i = deq.head
  for c in 0 ..< deq.count:
    yield (c, deq.data[i])
    i = (i + 1) and deq.mask

proc expandIfNeeded*[T](deq: var Deque[T]) =
  var cap = deq.mask + 1
  if unlikely(deq.count >= cap):
    var n = newSeq[T](cap * 2)
    for i, x in pairs(deq):
      shallowCopy(n[i], x)
    shallowCopy(deq.data, n)
    deq.mask = cap * 2 - 1
    deq.head = 0
    deq.tail = deq.count

proc addFirst*[T](deq: var Deque[T], item: T) =
  expandIfNeeded(deq)
  inc deq.count
  deq.head = (deq.head - 1) and deq.mask
  deq.data[deq.head] = item

proc addLast*[T](deq: var Deque[T], item: T) =
  expandIfNeeded(deq)
  inc deq.count
  deq.data[deq.tail] = item
  deq.tail = (deq.tail + 1) and deq.mask

proc peekFirst*[T](deq: Deque[T]): T =
  emptyCheck(deq)
  result = deq.data[deq.head]

proc peekLast*[T](deq: Deque[T]): T =
  emptyCheck(deq)
  result = deq.data[(deq.tail - 1) and deq.mask]

proc popFirst*[T](deq: var Deque[T]): T {.discardable.} =
  emptyCheck(deq)
  dec deq.count
  result = deq.data[deq.head]
  deq.head = (deq.head + 1) and deq.mask

proc popLast*[T](deq: var Deque[T]): T {.discardable.} =
  emptyCheck(deq)
  dec deq.count
  deq.tail = (deq.tail - 1) and deq.mask
  result = deq.data[deq.tail]

proc clear*[T](deq: var Deque[T]) =
  deq.count = 0
  deq.tail = deq.head

# -------------------------------------------------- #

let S = input(string)
let Q = input(int)
var rev = 0
var deq = initDeque[char]()
for e in S:
  deq.addLast(e)
for _ in 1 .. Q:
  let query = input(seq[string])
  if query[0] == "1":
    rev ^= 1
  else:
    let F = query[1].parseInt
    let C = query[2][0]
    if (rev + F) mod 2 == 0:
      deq.addLast(C)
    else:
      deq.addFirst(C)

var res = ""
if rev == 1:
  while deq.len > 0:
    res.add(deq.popLast())
else:
  while deq.len > 0:
    res.add(deq.popFirst())

echo res
