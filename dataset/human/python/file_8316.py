import strutils, sequtils
let get = iterator: string {.closure.} =
  for s in stdin.readAll.split: yield s
proc read: int = get().parseInt
template rep(p: untyped, n: int): seq = newSeqWith(n, p)

let
    k = read()
    n = read()
    a = read().rep(n)

var spaces: seq[int]

for index in 1..n:
    if index != n:
      spaces.add(a[index] - a[index - 1])
    else:
      spaces.add(k - a[n - 1] + a[0])

let max_value = max(spaces)
spaces.del(find(spaces, max_value))
echo spaces.foldl(a + b)
