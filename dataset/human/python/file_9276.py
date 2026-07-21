import strutils, sequtils

let
  nk = stdin.readline.split.map(parseint)
  n = nk[0]
  a = stdin.readline.split.map(parseint)

var
  k = nk[1]
  i = k
  loopsize : int
  beforeloopsize : int
  visitedat : array[1..200000, int]
  currentnode = 1
  currentlength = 1

# compute loopsize
while i > 0:
  if visitedat[currentnode] > 0:
    # ループ発見
    loopsize = currentlength - visitedat[currentnode]
    beforeloopsize = visitedat[currentnode]
    break
  else:
    visitedat[currentnode] = currentlength
    currentlength += 1
    i -= 1
    currentnode = a[currentnode - 1]

if loopsize > 0:
  k = ((k - beforeloopsize) mod loopsize) + beforeloopsize

currentnode = 1
while k > 0:
  currentnode = a[currentnode - 1]
  k -= 1

echo currentnode
