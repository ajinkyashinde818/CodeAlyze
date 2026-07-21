import sequtils, strutils, macros
 
let read* = iterator: string =
  while true: (for s in stdin.readLine.split: yield s)
 
template input*(T: static[typedesc]): untyped = 
  when T is int: read().parseInt
  elif T is float: read().parseFloat
  elif T is string: read()
  elif T is char: read()[0]
 
macro dump*(args: varargs[typed]): untyped =
  result = newNimNode(nnkStmtList)
  for x in args:
    let s = toStrLit(x)
    result.add quote do: stderr.write `s`, " = ", `x`, " "
  result.add quote do: stderr.write "\n"
 
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

import algorithm, math
# import bitops, lenientops, deques
# import heapqueue, sets, sugar, tables

# -------------------------------------------------- #

import tables

proc `//=`(n: var int, m: int) = n = n div m

var exponent = initTable[int, int]()
proc factorize(N: int) =
  var n = N
  var p = 2
  while p ^ 2 <= n:
    if n mod p == 0:
      n //= p
      if not exponent.hasKey(p):
        exponent[p] = 1
      else:
        exponent[p] += 1
    else:
      p += 1
  if n == 1:
    return
  if not exponent.hasKey(n):
    exponent[n] = 1
  else:
    exponent[n] += 1

let N = input(int)
factorize(N)
var res = 0
for C in exponent.values:
  for k in 0 .. 100:
    if k * (k + 1) <= 2 * C and 2 * C < (k + 1) * (k + 2):
      res += k
      break
echo res
