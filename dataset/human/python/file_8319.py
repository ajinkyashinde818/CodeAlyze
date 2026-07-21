import strutils,sequtils
import algorithm,sets,lists,critbits,sequtils,intsets,strutils,tables,math,heapqueue,future,deques

let read = iterator: string {.closure.} =
  while true:
    for s in stdin.readLine.split:
      yield s

let
  K, N = read().parseInt
  ai = stdin.readLine.split.map parseInt
var diffs = newSeq[int]()
for i in 0..<N-1:
  diffs.add(ai[i+1] - ai[i])
diffs.add(K - ai[^1] + ai[0])

echo K - diffs.max()
