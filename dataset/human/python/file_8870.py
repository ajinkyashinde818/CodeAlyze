import strutils, sequtils

let s = stdin.readline()
let wordList = ["eraser","erase","dreamer","dream"]
var p = s.len
while true:
    block b:
        for item in wordList.items:
            let pp = p-item.len
            if pp < 0:
                continue
            if s.continuesWith(item,pp):
                p = pp
                if p == 0:
                    echo "YES"
                    quit()
                break b
        echo "NO"
        quit()
