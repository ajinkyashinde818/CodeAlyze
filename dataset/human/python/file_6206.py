import strutils,sequtils
import algorithm,sets,lists,critbits,sequtils,intsets,strutils,tables,math,heapqueue,future

let read = iterator: string {.closure.} =
  while true:
    for s in stdin.readLine.split:
      yield s

var di = stdin.readline.reversed.mapIt(int(it) - int('0'))
di.add(0)
var dp = newSeqWith(di.len+1, newSeqWith(2, 10^9))  # dp[i][ちょうど払う or 1桁多くだしてお釣りをもらう]
dp[0][0] = 0

for i in 0..<di.len:
  let d = di[i]
  for flag in 0..1:
    let d = d + flag
    dp[i+1][0] = min(dp[i+1][0], dp[i][flag] + d)
    dp[i+1][1] = min(dp[i+1][1], dp[i][flag] + (10 - d))

echo dp[di.len][0]
