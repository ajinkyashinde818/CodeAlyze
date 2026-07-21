import strutils,sequtils
import algorithm,sets,lists,critbits,sequtils,intsets,strutils,tables,math,heapqueue,future,deques

let read = iterator: string {.closure.} =
  while true:
    for s in stdin.readLine.split:
      yield s

let
  N, K = read().parseInt
var A = newSeq[seq[int]]()
let ai = stdin.readLine.split.map(parseInt).mapIt(it-1)
A.add(ai)

var i = 1
while i <= K:
  let ai = (0..<N).mapIt(A[^1][A[^1][it]])
  A.add(ai)
  i *= 2

var
  k = K
  exp = 0
  v = 1
  ans = 0

while k > 0:
  while v * 2 <= k:
    v *= 2
    exp += 1
  ans = A[exp][ans]
  k -= v
  # echo (ans, k)
  exp = 0
  v = 1

echo ans + 1
