import sequtils, strutils, algorithm, tables, math

let (k,s) = (let t = stdin.readline.split.map(parseInt);(t[0],t[1]))

var ans = 0

for x in 0..k:
    for y in 0..k:
        if (0<=(s-(x+y)))and((s-(x+y)<=k)):
            inc(ans)

echo ans
