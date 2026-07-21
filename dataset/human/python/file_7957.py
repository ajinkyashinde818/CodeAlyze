import algorithm, sequtils, strutils

let read* = iterator: string {.closure.} =
  while true: (for s in stdin.readLine.split: yield s)

template input*(T: static[typedesc]): untyped = 
  when T is int: read().parseInt
  elif T is float: read().parseFloat
  elif T is string: read()

let N = input(int)
var A = newSeqWith(N, input(int))
var B = newSeqWith(N, input(int))
var res = 0
for k in countdown(28, 0):
  let mask = 1 shl (k + 1) - 1
  A.applyIt(it and mask); B.applyIt(it and mask); B.sort(cmp)
  let S = 1 shl k
  var cnt = 0
  for a in A:
    cnt += B.lowerBound(2 * S - a) - B.lowerBound(S - a)
    cnt += B.lowerBound(3 * S - a) - B.lowerBound(4 * S - a)
  if (cnt and 1) == 1:
    res += S
echo res
