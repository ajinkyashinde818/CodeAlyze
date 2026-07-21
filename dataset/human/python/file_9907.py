import sequtils, strutils, algorithm, math, sets, tables
when NimMajor == 0 and NimMinor <= 18: import future else: import sugar

var (A,B) = (let t = stdin.readline.split.map(parseInt);(t[0],t[1]))

echo lcm(A,B)
