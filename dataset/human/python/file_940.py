import algorithm, future, hashes, macros, math, sequtils, sets, strutils, tables, times, unicode, queues
 
macro unpack(rhs: seq, cnt: static[int]): auto =
  let t = genSym(); result = quote do:(let `t` = `rhs`;())
  if NimMinor <= 17:
    for i in 0..<cnt: result[0][1].add(quote do:`t`[`i`])
  else:
    for i in 0..<cnt: result[1].add(quote do:`t`[`i`])
 
template input(T: typedesc, cnt: Natural = 1): untyped =
  let line = stdin.readLine.split(" ")
  when T is int:         line.map(parseInt).unpack(cnt)
  elif T is float:       line.map(parseFloat).unpack(cnt)
  elif T is string:      line.unpack(cnt)
  elif T is char:        line.mapIt(it[0]).unpack(cnt)
  elif T is seq[int]:    line.map(parseInt)
  elif T is seq[float]:  line.map(parseFloat)
  elif T is seq[string]: line
  elif T is seq[char]:   line.mapIt(it[0])

proc floorMod*[T: SomeNumber](x, y: T): T =
  result = x mod y
  if (result > 0 and y < 0) or (result < 0 and y > 0): result += y

proc `%`(n,m:int):int = floorMod(n,m)
proc `%=`(n: var int, m: int)  = n = floorMod(n,m)
proc `//=`(n: var int, m: int) = n = n div m
proc `<<=`(n: var int, m: int) = n = n shl m
proc `>>=`(n: var int, m: int) = n = n shr m
proc `<?=`(n: var int, m: int) = n = min(n, m)
proc `>?=`(n: var int, m: int) = n = max(n, m)
proc newSeq2[T](n1, n2: Natural): seq[seq[T]] = newSeqWith(n1, newSeq[T](n2))
proc newSeq3[T](n1, n2, n3: Natural): seq[seq[seq[T]]] = newSeqWith(n1, newSeqWith(n2, newSeq[T](n3)))
 
proc spacingEcho(things: varargs[string,`$`]) =
  for thing in things:
    stdout.write(thing)
    stdout.write(" ")
  stdout.write("\n")
proc spacingEcho[T](things: seq[T]) =
  for thing in things:
    stdout.write(thing)
    stdout.write(" ")
  stdout.write("\n")
proc spacingEcho[T](things: seq[seq[T]]) =
  for thing in things:
    spacingEcho thing
proc spacingEchoPlusOne(things: varargs[int]) =
  for thing in things:
    stdout.write(thing+1)
    stdout.write(" ")
  stdout.write("\n")
proc spacingEchoPlusOne(things: seq[int]) =
  for thing in things:
    stdout.write(thing+1)
    stdout.write(" ")
  stdout.write("\n")
proc spacingEchoPlusOne(things: seq[seq[int]]) =
  for thing in things:
    spacingEchoPlusOne thing
    
# -------------------------------------------------- #
# ModInt : Z/1000000007Z
# Remember as an int in 0..<1000000007
# However $ModInt(-3)=="-3". So if arg may be negative, use $newModInt(-3)==1000000004
# tested in ARC 190330

const MOD = int(1000000007)
type ModInt* = distinct int

proc newModInt(x:int): ModInt = ModInt(floorMod(x, MOD))
proc `-`(x: ModInt): ModInt = ModInt(floorMod(-int(x), MOD))

proc `+`(x:ModInt, y:ModInt): ModInt = ModInt(floorMod(int(x)+int(y), MOD))
proc `+`(x:ModInt, y:int): ModInt = ModInt(floorMod(int(x)+y, MOD))
proc `+`(x:int, y:ModInt): ModInt = ModInt(floorMod(x+int(y), MOD))
proc `+=`(x: var ModInt, y: ModInt or int)  = x = x + y
proc `-`(x:ModInt, y:ModInt): ModInt = ModInt(floorMod(int(x)-int(y), MOD))
proc `-`(x:ModInt, y:int): ModInt = ModInt(floorMod(int(x)-y, MOD))
proc `-`(x:int, y:ModInt): ModInt = ModInt(floorMod(x-int(y), MOD))
proc `-=`(x: var ModInt, y: ModInt or int)  = x = x - y

proc `==`(x:ModInt, y:ModInt): bool = ((int(x)-int(y)) mod MOD == 0)
proc `==`(x:ModInt, y:int): bool = ((int(x)-y) mod MOD == 0)
proc `==`(x:int, y:ModInt): bool = ((x-int(y)) mod MOD == 0)
proc `!=`(x:ModInt, y:ModInt): bool = not(x==y)
proc `!=`(x:ModInt, y:int): bool = not(x==y)
proc `!=`(x:int, y:ModInt): bool = not(x==y)

proc `*`(x:ModInt, y:ModInt): ModInt = ModInt(floorMod(int(x)*int(y), MOD))
proc `*`(x:ModInt, y:int): ModInt = ModInt(floorMod(int(x)*y, MOD))
proc `*`(x:int, y:ModInt): ModInt = ModInt(floorMod(x*int(y), MOD))
proc `*=`(x: var ModInt, y: ModInt or int)  = x = x * y

proc `^`(x:ModInt, y:int): ModInt =
  if x==ModInt(0):
    if y==0:
      return ModInt(1)
    else:
      return ModInt(0)
  var x = x
  var y = floorMod(y, MOD-1) #x^(MOD-1)==1
  result = ModInt(1)
  while y>0:
    if (y and 1) != 0:
      result *= x
    y = y shr 1
    x *= x
proc inv(x:ModInt): ModInt = x^(-1)
proc inv(x:int): ModInt = ModInt(x)^(-1)

proc `/`(x:ModInt, y:ModInt):ModInt = x * inv(y)
proc `/`(x:ModInt, y:int):ModInt = x * inv(ModInt(y))
proc `/`(x:int, y:ModInt):ModInt = ModInt(x) * inv(y)
proc `/=`(x: var ModInt, y: ModInt or int)  = x = x / y
proc `$`(x:ModInt):string = $int(x)



# -------------------------------------------------- #

var N = input(int)
var bws = input(string)
var lrs = newSeq[char](2*N)

for i in 0..<2*N:
  if i mod 2 == 0:
    if bws[i] == 'B':
      lrs[i] = 'L'
    else:
      lrs[i] = 'R'
  else:
    if bws[i] == 'B':
      lrs[i] = 'R'
    else:
      lrs[i] = 'L'


#echo lrs


var atu = 0
for a in lrs:
  if a == 'L':
    atu += 1
  else:
    atu -= 1
  if atu < 0:
    echo 0
    quit()
if atu != 0:
  echo 0
  quit()


var re = newModInt(1)
atu = 0
for a in lrs:
  if a == 'L':
    atu += 1
  else:
    re *= atu
    atu -= 1

#echo re


for x in 1..N:
  re *= x

echo re



#[

var lrs = newSeq[char](2*N)

for i in 0..<2*N:
  if i== 0:
    if bws[i] == 'b':
      lrs[i] = 'l'

]#
