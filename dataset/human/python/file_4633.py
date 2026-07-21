import sequtils,strutils,algorithm,math,future,macros
import sets,tables,intsets,queues
template get*():string = stdin.readLine().strip()
macro unpack*(arr: auto,cnt: static[int]): auto =
  let t = genSym(); result = quote do:(let `t` = `arr`;())
  for i in 0..<cnt: result[0][1].add(quote do:`t`[`i`])
template times*(n:int,body) = (for _ in 0..<n: body)
template `max=`*(x,y) = x = max(x,y)
template `min=`*(x,y) = x = min(x,y)
proc toSeq(str:string):seq[char] = result = @[];(for s in str: result.add(s))
proc split(n:int):auto = ($n).toSeq().mapIt(it.ord- '0'.ord)
proc join(n:seq[int]):int = n.mapIt($it).join("").parseInt()

let S = stdin.readLine()
echo S[0..^9]
