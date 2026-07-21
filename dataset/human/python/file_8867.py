from unicode import reversed
from sequtils import map

var
    s = stdin.readline
    words = @["eraser","erase","dreamer","dream"]

s=s.reversed
words = words.map(proc (x:string):string=x.reversed)

var
    flag = true
    i = 0

while flag == true:
    flag = false
    if s.len-i >= 7:
        if s[i..<i+7] == words[2]:
            i += 7
            flag = true
    if s.len-i >= 6:
        if s[i..<i+6] == words[0]:
            i += 6
            flag = true
    if s.len-i >= 5:
        if s[i..<i+5] == words[1]:
            i += 5
            flag = true
    if s.len-i >= 5:
        if s[i..<i+5] == words[3]:
            i += 5
            flag = true
    if s.len-i == 0:
        flag = true
        break

if flag == true: echo "YES"
else: echo "NO"
