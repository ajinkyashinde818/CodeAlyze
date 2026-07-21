import strformat, macros, algorithm, tables, sets, lists,
    intsets, critbits, sequtils, strutils, math, times,
    sugar, options, deques, bitops, heapqueue

const
  InfInt = 1e18.int
  NegInfInt = -1e18.int
  MOD = 10^9 + 7

template loop(n: int, body) = (for _ in 0..<n: body)
template `max=`(x, y) = x = max(x, y)
template `min=`(x, y) = x = min(x, y)
template `mod=`(x, y) = x = x mod y
template `sumMod=`(x, y, m = MOD) = x = (x + y) mod m
template `prodMod=`(x, y, m = MOD) = x = (x * y) mod m

let readNext = iterator(getsChar: bool = false): string {.closure.} =
  for s in stdin.readAll.split:
    if getsChar:
      for i in 0..<s.len():
        yield s[i..i]
    else:
      yield s

proc read(t: typedesc[string]): string = readNext()
proc read(t: typedesc[char]): char = readNext(true)[0]
proc read(t: typedesc[int]): int = readNext().parseInt
proc read(t: typedesc[float]): float = readNext().parseFloat

macro read(t: typedesc, n: varargs[int]): untyped =
  var repStr = ""
  for arg in n:
    repStr &= &"({arg.repr}).newSeqWith "
  parseExpr(&"{repStr}read({t})")

var
  N = read(int)
  K = read(int)
  A = read(int, N)
  mem = newSeqWith[int](N, -1)

var
  i = 0
  next = 1
while mem[next-1] == -1 and i < K:
  mem[next-1] = i
  next = A[next-1]
  i += 1

if i == K:
  echo A[mem.find(i-1)]
  quit()

let
  loopCnt = i - mem[next-1]
  remain = (K - i - 1) mod loopCnt

var result = A[next-1]

remain.loop:
  result = A[result-1]

echo result
