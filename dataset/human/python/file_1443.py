import strutils, sequtils
let get = iterator: string {.closure.} =
  for s in stdin.readAll.split: yield s
proc read: int {.inline.} = get().parseInt
template rep(a,b): seq = newSeqWith(b,a)

let n,m = read()
let a = get().rep n
let b = get().rep m
for i in 0..n-m:
  for j in 0..n-m:
    for y in 0..<m:
      if a[j+y][i..<i+m] != b[y]: break
      if y == m-1:
        echo "Yes"; quit 0
echo "No"
