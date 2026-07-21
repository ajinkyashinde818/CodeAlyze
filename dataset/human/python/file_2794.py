import strutils,sequtils
import algorithm,sets,lists,critbits,sequtils,intsets,strutils,tables,math,heapqueue,future

let read = iterator: string {.closure.} =
  while true:
    for s in stdin.readLine.split:
      yield s


proc factorization(n: int): seq[(int, int)] = 
  var
    arr = newSeq[(int, int)]()
    temp: int = n
  for i in 2..<(int(sqrt(float(n)))+1):
    if temp mod i == 0:
      var cnt = 0
      while temp mod i == 0:
        cnt += 1
        temp = temp div i
      arr.add((i, cnt))

  if temp!=1:
    arr.add((temp, 1))

  if arr==[]:
    arr.add((n, 1))

  return arr

let N = read().parseInt
if N == 1:
  echo 0
  quit()

var
  pfactors = initTable[int, int]()
  used = initTable[int, int]()
  ans = 0
for pf in factorization(N):
  var
    cnt = pf[1]
    i = 1
    score = 0
  while i <= cnt:
    cnt -= i
    score += 1
    i += 1
  ans += score

echo ans
