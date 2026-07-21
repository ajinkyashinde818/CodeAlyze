import sequtils
import strutils


proc getInts(): seq[int] =
    readLine(stdin).split().map(parseInt)

proc getsaidai(a: int, b: int): int =
    var res = 0
    var modd = 0
    var a = a
    var b = b
    for index in 0..10000:
        if a > b:
            modd = (a mod b)
            a = b
            res = b
            b = modd
        else:
            modd = (b mod a)
            b = a
            res = a
            a = modd
        if modd == 0:
            break
    return res

let ab = getInts()
let a = ab[0]
let b = ab[1]

var saidai = getsaidai(a, b)

var kotae = 0
if saidai == 0:
    kotae = a * b
else:
    kotae = int(a * b / saidai)

echo kotae
