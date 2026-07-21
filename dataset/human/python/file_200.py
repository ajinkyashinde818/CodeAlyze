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

proc readLine*(): string = stdin.readLine()
proc readSeq*(): seq[string] = readLine().strip().split()
proc readSeq*(n: Natural): seq[string] =
  result = newSeq[string](n)
  for i in 0..<n:
    result[i] = readLine().strip()
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
proc newSeq2*[T](n1, n2: Natural): seq2[T] =
  newSeqWith(n1, newSeq[T](n2))
type seq3*[T] = seq[seq[seq[T]]]
proc newSeq3*[T](n1, n2, n3: Natural): seq3[T] =
  newSeqWith(n1, newSeqWith(n2, newSeq[T](n3)))

#------------------------------------------------------------------------------#

proc main() =
  let n = readInt1()

  var k = -1
  for i in 1..(2 * n):
    if (i * (i - 1) div 2) == n:
      k = i
      break

  if k == -1:
    echo "No"
    return

  var g = newSeq2[int](k, 0)
  var cnt = 1
  for i in 0..<k:
    for j in (i + 1)..<k:
      g[i].add(cnt)
      g[j].add(cnt)
      cnt += 1

  echo "Yes"
  echo k
  for i in 0..<k:
    stdout.write(g[i].len())
    for v in g[i]:
      stdout.write(" ")
      stdout.write(v)
    echo ""


main()
