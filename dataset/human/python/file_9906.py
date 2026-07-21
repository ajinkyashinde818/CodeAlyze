import strutils,sequtils
import algorithm,sets,lists,critbits,sequtils,intsets,strutils,tables,math,heapqueue,future

let read = iterator: string {.closure.} =
  while true:
    for s in stdin.readLine.split:
      yield s

let A, B = read().parseInt
echo lcm(A, B)
