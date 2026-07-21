import strutils
import sequtils
import algorithm
import math
import queues
import tables
import sets
import future

const INF* = int(1e18 + 373)

proc readLine*(): string =
  stdin.readLine()
proc readSeq*(): seq[string] =
  readLine().strip().split()
proc readSeq*(n: Natural): seq[string] =
  result = newSeq[string](n)
  for i in 0..<n:
    result[i] = readLine().strip()
proc readInt1*(): int =
  readSeq().map(parseInt)[0]
proc readInt2*(): (int, int) =
  let a = readSeq().map(parseInt)
  return (a[0], a[1])
proc readInt3*(): (int, int, int) =
  let a = readSeq().map(parseInt)
  return (a[0], a[1], a[2])
proc readInt4*(): (int, int, int, int) =
  let a = readSeq().map(parseInt)
  return (a[0], a[1], a[2], a[3])
proc newSeqWith*[T](n: Natural; e: T): seq[T] =
  result = newSeq[T](n)
  for i in 0..<n:
    result[i] = e
type seq2*[T] = seq[seq[T]]
proc newSeq2*[T](n1, n2: Natural): seq2[T] =
  newSeqWith(n1, newSeq[T](n2))
type seq3*[T] = seq[seq[seq[T]]]
proc newSeq3*[T](n1, n2, n3: Natural): seq3[T] =
  newSeqWith(n1, newSeqWith(n2, newSeq[T](n3)))

#------------------------------------------------------------------------------#

proc main() =
  let (a, b, c) = readInt3()

  var eatc = min(c, a + b + 1)
  let ans = b + eatc
  echo ans


main()
