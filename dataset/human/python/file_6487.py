import strutils,sequtils
import algorithm,sets,lists,critbits,sequtils,intsets,strutils,tables,math,heapqueue,future,deques

let read = iterator: string {.closure.} =
  while true:
    for s in stdin.readLine.split:
      yield s

let
  S = read()
  Q = read().parseInt
var
  deque = initDeque[char]()
  f = 0
for c in S:
  deque.addLast(c)

for _ in 1..Q:
  let
    v = stdin.readLine.split
    K = v[0].parseInt
  if K == 1:
    f = f xor 1
  else:
    let
      F = v[1].parseInt - 1
      C = v[2][0]
    if (f xor F) == 0:
      deque.addFirst(C)
    else:
      deque.addLast(C)

var ans_seq = deque.toSeq()
if f == 1:
  ans_seq.reverse()
echo ans_seq.join("")
