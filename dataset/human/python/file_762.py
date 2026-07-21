import strutils, sequtils, algorithm, math, sets

proc YESNO(r: bool, yes: string = "YES", no: string = "NO") =
  if r: echo yes
  else: echo no

proc getInt(): int =
  stdin.readLine.parseInt()

proc getInts(): seq[int] =
  stdin.readLine.split.map(parseInt)

proc getIntLines(lines: int): seq[int] =
  mapIt(0..(lines-1), stdin.readLine.parseInt())

when NimMajor <= 0 and NimMinor <= 13:
  proc sort[T](a: var openArray[T], order = SortOrder.Ascending) =
    sort(a, system.cmp[T], order)
  proc sorted[T](a: var openArray[T], order = SortOrder.Ascending): seq[T] =
    sorted(a, system.cmp[T], order)

let
  nr = getInts()
  N = nr[0]
  R = nr[1]
if N < 10:
  echo R + 100 * (10 - N)
else:
  echo R
