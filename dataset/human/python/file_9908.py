import strutils, sequtils, math, algorithm, tables, sets, lists, intsets, critbits, sugar
const INF = 10 ^ 10
proc nextInt(): int =
    stdin.readLine.parseInt
proc nextSeq(): seq[int] =
    stdin.readLine.split.map(parseInt)

var A, B: int
(A, B) = nextSeq()

proc gcd(a, b: int): int =
    if b == 0:
        return a
    return gcd(b, a mod b)

echo A * B div gcd(A, B)
