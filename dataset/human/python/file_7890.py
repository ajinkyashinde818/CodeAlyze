import macros, algorithm, tables, sets, lists, queues, intsets, critbits, sequtils, strutils, math, future

proc readInt(): int =
  result = stdin.readLine.parseInt

proc readInts(): seq[int] =
  result = stdin.readLine.split.map(parseInt)

var S = stdin.readLine

while true:
  if(S.find('a')== -1):
    echo "No"
    break
  elif(S.find('b')== -1):
    echo "No"
    break
  elif(S.find('c')== -1):
    echo "No"
    break
  else:
    echo "Yes"
    break
