import strutils
import sequtils

proc getInt(): int =
    parseInt(readLine(stdin))

proc getInts(): seq[int] =
    readLine(stdin).split().map(parseInt)

let N = getInt()
let A = getInts();
let B = getInts();
let C = getInts();

var manzoku = 0
var privRyouri = 0
for i in 0..<N:
    let bindex = A[i]
    if (privRyouri != 0 and privRyouri + 1 == bindex) :
        manzoku += C[privRyouri-1]
    privRyouri = bindex;
    manzoku += B[bindex-1]

echo  manzoku
