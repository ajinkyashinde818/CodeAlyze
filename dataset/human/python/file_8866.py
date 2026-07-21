import strutils
import sequtils
import algorithm

proc reverse(s: string): string =
    s.toSeq.reversed.join

var
    S = stdin.readLine.reverse
    C = @["dreamer", "eraser", "dream", "erase"].mapIt(it.reverse)

proc isOk(s: string): bool =
    if s.len == 0:
        return true

    for c in C:
        if s.len < c.len:
            continue
        if s.startsWith(c):
            return isOk(s[c.len..^1])
    return false

if S.isOk:
    echo "YES"
else:
    echo "NO"
