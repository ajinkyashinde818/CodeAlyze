import strformat, macros, algorithm, tables, sets, lists,
    intsets, critbits, sequtils, strutils, math, times,
    sugar, options, deques, bitops

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

proc primeFactorize*(n: Positive): CountTable[int] =
  if n == 1:
    return

  var n = n
  for i in 2..n.toFloat.sqrt.toInt:
    while n mod i == 0:
      n = n div i
      result.inc(i)

  if n != 1:
    result.inc(n)

var
  N: int

when isMainModule:
  N = read(int)

  var result = 0
  for k, v in N.primeFactorize.pairs:
    var
      i = 1
      v = v
    while i <= v:
      result += 1
      v -= i
      i += 1

  echo result
