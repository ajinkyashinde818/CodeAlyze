import sequtils, strutils, algorithm, math, future, sets, tables, hashes

proc solve() =

    var n,m : int
    (n,m) = stdin.readLine.split.map(parseInt)
    var d2a : seq[string]
    var d2b : seq[string]
    for i in 0 ..< n : 
        d2a.safeadd(stdin.readLine)

    for i in 0 ..< m : 
        d2b.safeadd(stdin.readLine)

    for i in 0 ..< n - m + 1: 
        for j in 0 ..< n - m + 1 : 
            block judge : 
                for ii in 0 ..< m : 
                    for jj in 0 ..< m : 
                        if d2a[i + ii][j + jj] != d2b[ii][jj] : 
                            break judge
                echo "Yes"
                return
    echo "No"
    return



solve()
