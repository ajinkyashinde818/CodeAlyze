import algorithm, complex, macros, math, sequtils, sets, strutils, tables, times
when NimMajor == 0 and NimMinor <= 19:
  import future
else:
  import sugar, strformat

macro unpack*(rhs: seq, cnt: static[int]): auto =
  let v = genSym(); result = quote do:(let `v` = `rhs`;())
  when NimMajor == 0 and NimMinor <= 17:
    for i in 0 ..< cnt: result[0][1].add(quote do:`v`[`i`])
  else:
    for i in 0 ..< cnt: result[1].add(quote do:`v`[`i`])

template input*(T: typedesc, cnt: Natural = 1): untyped =
  let line = stdin.readLine.split(" ")
  when T is int:         line.map(parseInt).unpack(cnt)
  elif T is float:       line.map(parseFloat).unpack(cnt)
  elif T is string:      line.unpack(cnt)
  elif T is char:        line.mapIt(it[0]).unpack(cnt)
  elif T is seq[int]:    line.map(parseint)
  elif T is seq[float]:  line.map(parseFloat)
  elif T is seq[string]: line
  elif T is seq[char]:   line.mapIt(it[0])

macro puts*(arg: varargs[untyped]): untyped =
  result = newNimNode(nnkStmtList)
  for x in arg:
    let name = toStrLit(x)
    result.add(quote do: stderr.write `name`, ": " , `x`, "\n")

proc `<?=`*(n: var SomeNumber, m: SomeNumber) = n = min(n, m)
proc `>?=`*(n: var SomeNumber, m: SomeNumber) = n = max(n, m)

# -------------------------------------------------- #

var S = input(string)
S.reverse()
let N = "#" & S
let M = N.high
var dp: array[0 .. 10 ^ 6 + 1, array[0 .. 1, array[0 .. 9, int]]]
for i in 0 .. M:
  for k in 0 .. 1:
    for j in 0 .. 9:
      dp[i][k][j] = 10 ^ 9

dp[0][0][0] = 0

for i in 1 .. M:
  let d = N[i .. i].parseInt
  for j in 0 .. 9:
    if j < d:
      dp[i][1][j] <?= min(dp[i - 1][0]) + j + (10 + j - d)
    else:
      dp[i][0][j] <?= min(dp[i - 1][0]) + j + (j - d)
    if j == 0:
      let j2 = 9
      dp[i][1][j] <?= min(dp[i - 1][1]) + 0 + (j2 - d)
    else:
      let j2 = j - 1
      if j2 < d:
        dp[i][1][j] <?= min(dp[i - 1][1]) + j + (10 + j2 - d)
      else:
        dp[i][0][j] <?= min(dp[i - 1][1]) + j + (j2 - d)

echo min(min(dp[M][0]), min(dp[M][1]) + 1)
