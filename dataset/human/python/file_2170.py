import strutils
import sequtils
import algorithm
import math
import queues
import tables
import sets
import logging
import future

const INF* = int(1e18 + 373)

proc readSeq*(): seq[string] = stdin.readLine().strip().split()
proc readSeq*(n: Natural): seq[string] =
  result = newSeq[string](n)
  for i in 0..<n:
    result[i] = stdin.readLine().strip()

proc readInt1*(): int = readSeq().map(parseInt)[0]
proc readInt2*(): (int, int) =
  let a = readSeq().map(parseInt)
  return (a[0], a[1])
proc readInt3*(): (int, int, int) =
  let a = readSeq().map(parseInt)
  return (a[0], a[1], a[2])
proc readInt4*(): (int, int, int, int) =
  let a = readSeq().map(parseInt)
  return (a[0], a[1], a[2], a[3])

type seq2*[T] = seq[seq[T]]
proc newSeq2*[T](n1, n2: Natural): seq2[T] = newSeqWith(n1, newSeq[T](n2))

#------------------------------------------------------------------------------#

proc main() =
  let (d, g) = readInt2()
  var ps = newSeq[(int, int)](d)
  for i in 0..<d:
    ps[i] = readInt2()

  var ans = INF
  for s in 0..<(1 shl d):
    var sum = 0
    var cnt = 0
    for i in 0..<d:
      if (s and (1 shl i)) != 0:
        sum += 100 * (i + 1) * ps[i][0] + ps[i][1]
        cnt += ps[i][0]

    var xs = newSeq[int](0)
    for i in 0..<d:
      if (s and (1 shl i)) == 0:
        for j in 0..<ps[i][0]:
          xs.add(100 * (i + 1))

    xs.sort(cmp[int])
    if xs.len() != 0:
      xs.reverse()

    var k = 0
    while k < xs.len() and sum < g:
      sum += xs[k]
      cnt += 1
      k += 1

    if sum < g:
      continue

    ans = min(ans, cnt)

  echo ans

main()
