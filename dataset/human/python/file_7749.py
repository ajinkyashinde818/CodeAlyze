{.push hints:off.}
import algorithm, hashes, macros, math, sequtils, sets, strutils, tables, times, unicode, queues
when NimMinor <= 17: import future else: import sugar

macro unpack(rhs: seq, cnt: static[int]): auto =
  let t = genSym(); result = quote do:(let `t` = `rhs`;())
  when NimMinor <= 17:
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
proc `:<=`[T](n: var T, m: T):bool {.discardable.}=
  result = n > m
  if result:
    n = m
proc `:>=`[T](n: var T, m: T):bool {.discardable.}=
  result = n < m
  if result:
    n = m
proc newSeq2[T](n1, n2: Natural): seq[seq[T]] = newSeqWith(n1, newSeq[T](n2))
proc newSeq3[T](n1, n2, n3: Natural): seq[seq[seq[T]]] = newSeqWith(n1, newSeqWith(n2, newSeq[T](n3)))
proc spacingStr(things: varargs[string,`$`]):string =
  result = ""
  for thing in things:
    result &= thing
    result &= " "
  result &= "\n"
proc spacingStr[T](things: seq[T]):string =
  result = ""
  for thing in things:
    result &= $thing
    result &= " "
  result &= "\n"
proc spacingStr[T](things: seq[seq[T]]):string =
  result = ""
  for thing in things:
    result &= spacingStr(thing)
proc spacingStrPlusOne(things: varargs[int]):string =
  result = ""
  for thing in things:
    result &= $(thing+1)
    result &= " "
  result &= "\n"
proc spacingStrPlusOne[T](things: seq[T]):string =
  result = ""
  for thing in things:
    result &= $(thing+1)
    result &= " "
  result &= "\n"
proc spacingStrPlusOne[T](things: seq[seq[T]]):string =
  result = ""
  for thing in things:
    result &= spacingStrPlusOne(thing)
proc spacingEcho(things: varargs[string,`$`]) = stdout.write(spacingStr(things))
proc spacingEcho[T](things: seq[T]) = stdout.write(spacingStr(things))
proc spacingEcho[T](things: seq[seq[T]]) = stdout.write(spacingStr(things))
proc spacingEchoPlusOne(things: varargs[int]) = stdout.write(spacingStrPlusOne(things))
proc spacingEchoPlusOne(things: seq[int]) = stdout.write(spacingStrPlusOne(things))
proc spacingEchoPlusOne(things: seq[seq[int]]) = stdout.write(spacingStrPlusOne(things))
template myDump*(things: varargs[string,`$`]) =
  when NimMinor >= 17:
    let sr = spacingStr(things)
    let line = instantiationInfo().line
    let lineName = "LINE" & '0'.repeat(4-($line).len) & ($line) & "...>  "
    stdout.write(lineName & sr)
template myDump*[T](things: seq[T]) =
  when NimMinor >= 17:
    let sr = spacingStr(things)
    let line = instantiationInfo().line
    let lineName = "LINE" & '0'.repeat(4-($line).len) & ($line) & "...>  "
    stdout.write(lineName & sr)
template myDump*[T](things: seq[seq[T]]) =
  when NimMinor >= 17:
    let sr = spacingStr(things)
    let line = instantiationInfo().line
    let lineName = "LINE" & '0'.repeat(4-($line).len) & ($line) & "...v\n"
    stdout.write(lineName & sr)
iterator items(n:int):int = 
  for i in 0..<n:
    yield i
{.pop.}

# -------------------------------------------------- #


discard """
1 <= N
0 <= K <= N
1 <= S <= 1_000_000_000
"""

var (N,K,S) = input(int,3)

var res = newSeq[int]()


if N==1:
  if K==1:
    res.add S
  else:
    res.add 4567890 #uso

elif K==0:
  for _ in N:
    res.add 65098768 #uso

elif N==K:
  for _ in K:
    res.add S

elif S==1_000_000_000:
  for _ in K+1:
    res.add 500_000_000
  while res.len < N:
    res.add 500_000_001

elif S==1:
  for _ in K:
    res.add 1
  while res.len < N:
    res.add 114514

else:
  res.add 1
  for _ in K:
    res.add (S-res[^1])
  while res.len < N:
    res.add S+1



spacingEcho res
