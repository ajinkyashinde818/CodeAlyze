import sequtils, strutils, algorithm

let
  s = stdin.readline
  q = stdin.readline.parseInt
var
  t = newSeqWith(2, @[""])
  rev = 0

for _ in 1..q:
  let query = stdin.readline.split
  if query[0] == "1":
    rev = rev xor 1
  elif query[0] == "2":
    t[(parseInt(query[1])-1) xor rev].add(query[2])

let
  pre = join(reversed(t[0]))
  pos = join(t[1])

if rev == 0:
  echo (pre & s & pos)
else:
  echo reversed(toSeq((pre & s & pos).items)).mapIt($it).join
  # echo (pre & reversed(toSeq(s.items)).mapIt($it).join & pos)
