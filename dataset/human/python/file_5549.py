import streams, strformat, sequtils, strutils, algorithm, math, future, sets, tables, hashes
proc `ceilDiv`*[T](x, y: T): T = x div y + ord(x mod y != 0)
proc `//=`*(x: var SomeInteger; y: SomeInteger) = x = x div y
proc `%=`*(x: var SomeInteger; y: SomeInteger) = x = x mod y

var
    S = stdin.readLine
    idx = 0
    jdx = S.len-1
    flag = true
    ans = 0

# while idx != jdx and idx < S.len and jdx >= 0:
while idx <= jdx:
    if S[idx] == S[jdx]:
        idx += 1
        jdx -= 1
    else:
        if S[idx] == 'x':
            idx += 1
            ans += 1
        elif S[jdx] == 'x':
            jdx -= 1
            ans += 1
        else:
            flag = false
            break
if flag:
    echo ans
else:
    echo -1
