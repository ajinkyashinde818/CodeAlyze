import sequtils,strutils
var
    N = stdin.readline.parseInt
    f : bool
    i = 0
    n = 0
    T : array[1000,array[1000,int]]
while n <= N:
    i += 1
    n += i
    if n == N:
        f = true
        break
if f:
    echo "Yes"
    var p = 1
    echo(i + 1)
    for q in 1..i + 1:
        stdout.write($i & " ")
        for t in 1 .. i + 1:
            if q == t:
                continue
            elif t < q:
                T[q][t] = T[t][q]
            else:
                T[q][t] = p
                p += 1
            if t == i + 1:
                stdout.write($T[q][t] & "\n")
            else:
                stdout.write($T[q][t] & " ")
    stdout.write("\n")
else:
    echo "No"
