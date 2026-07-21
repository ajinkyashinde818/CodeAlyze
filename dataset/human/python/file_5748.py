import strutils,sequtils
import algorithm,sets,lists,critbits,sequtils,intsets,strutils,tables,math,heapqueue,future

let read = iterator: string {.closure.} =
  while true:
    for s in stdin.readLine.split:
      yield s

let
  N = read().parseInt
  ai = stdin.readLine.split.mapIt(it.parseInt - 1)
  bi = stdin.readLine.split.map parseInt
  ci = stdin.readLine.split.map parseInt

var
  ans = 0
  j = -2
for i in 0..<N:
  let
    a = ai[i]
    b = bi[a]
  ans += b
  if j + 1 == a:
    ans += ci[j]
  j = a
  
echo ans
