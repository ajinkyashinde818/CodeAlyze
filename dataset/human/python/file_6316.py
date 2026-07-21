import strutils,sequtils
import algorithm,sets,lists,critbits,sequtils,intsets,strutils,tables,math,heapqueue,future

let read = iterator: string {.closure.} =
  while true:
    for s in stdin.readLine.split:
      yield s

let N = read().parseBiggestInt

if N mod 2 == 1:
  echo 0
  quit()

let
  S = $N
  L = S.len

var
  ans: int64 = 0
  divisor: int64 = 10

while N >= divisor:
  ans += N div divisor
  divisor *= 5

echo ans
