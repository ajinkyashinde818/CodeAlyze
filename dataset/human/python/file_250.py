import algorithm
import future
import macros
import math
import queues
import sequtils
import sets
import strutils
import tables

const INF* = int(1e18 + 373)

proc readLine*(): string =
  stdin.readLine().strip()
proc readSeq*(): seq[string] =
  readLine().split()
proc readSeq*(n: Natural): seq[string] =
  result = newSeqWith(n, readLine())
proc readIntSeq*(): seq[int] =
  result = readSeq().map(parseInt)
proc readIntSeq*(n: Natural): seq[int] =
  result = readSeq(n).map(parseInt)
proc readInt1*(): int =
  readLine().parseInt()
proc readInt2*(): (int, int) =
  let a = readIntSeq(); return (a[0], a[1])
proc readInt3*(): (int, int, int) =
  let a = readIntSeq(); return (a[0], a[1], a[2])
proc readInt4*(): (int, int, int, int) =
  let a = readIntSeq(); return (a[0], a[1], a[2], a[3])

proc newSeqOf*[T](n: Natural; e: T): seq[T] =
  result = newSeq[T](n)
  result.fill(e)
proc newSeq*[T](n: Natural; e: T): seq[T] =
  newSeqOf[T](n, e)
type seq2*[T] = seq[seq[T]]
proc newSeq2*[T](n1, n2: Natural): seq2[T] =
  newSeqOf(n1, newSeq[T](n2))
proc newSeq2*[T](n1, n2: Natural; e: T): seq2[T] =
  newSeqOf(n1, newSeqOf(n2, e))
type seq3*[T] = seq[seq[seq[T]]]
proc newSeq3*[T](n1, n2, n3: Natural): seq3[T] =
  newSeqOf(n1, newSeqOf(n2, newSeq[T](n3)))
proc newSeq3*[T](n1, n2, n3: Natural; e: T): seq3[T] =
  newSeqOf(n1, newSeqOf(n2, newSeqOf(n3, e)))

when defined(ENABLE_DEBUG_MACRO):
  macro debug*(args: varargs[untyped]): untyped =
    result = nnkStmtList.newTree()
    for i in 0..<args.len():
      let par1 = newIdentNode("stderr")
      let par2 = newLit(args[i].repr)
      let par3 = newLit(" = ")
      let par4 = args[i]
      result.add(newCall("write", par1, par2, par3, par4))
      if i + 1 < args.len():
        result.add(newCall("write", newIdentNode("stderr"), newLit(", ")))
    result.add(newCall("writeLine", newIdentNode("stderr"), newLit("")))
else:
  macro debug*(args: varargs[untyped]): untyped =
    result = nnkDiscardStmt.newTree(newLit(nil))

#------------------------------------------------------------------------------#
#------------------------------------------------------------------------------#

proc main() =
  let n = readInt1()
  let a = readIntSeq()

  var dp = newSeq2[int](n, 2)
  dp[n - 1][0] = a[n - 1]
  dp[n - 1][1] = -a[n - 1]
  for i in countdown(n - 2, 0):
    dp[i][0] = max(a[i] + dp[i + 1][0], -a[i] + dp[i + 1][1])
    dp[i][1] = max(-a[i] + dp[i + 1][0], a[i] + dp[i + 1][1])
  echo dp[0][0]

main()
