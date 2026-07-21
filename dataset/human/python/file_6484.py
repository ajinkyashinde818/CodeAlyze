import strutils, sequtils
let get = iterator: string {.closure.} =
  for s in stdin.readAll.split: yield s
let read = proc: int = get().parseInt

var fr, bc = newString(0)
var rv = false

let s = get()
let q = read()
for _ in 1..q:
  case read():
    of 1: rv = not rv
    of 2:
      if read() == 1 xor rv: fr.add get()[0]
      else: bc.add get()[0]
    else: raise

import algorithm
fr.reverse
var ss = fr & s & bc
if rv: ss.reverse
echo ss
