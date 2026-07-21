import Foundation
let arr = ["dream", "erase", "eraser", "dreamer"]
var S = readLine()!
var flag = false
repeat {
    flag = false
    for s in arr {
        if S.hasSuffix(s) {
            S = S.substringToIndex(S.endIndex.advancedBy(-s.characters.count))
            flag = true
        }
    }
} while flag
print(S=="" ?"YES":"NO")
