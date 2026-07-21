import Foundation
let a = readLine()!.split(separator: " ").map({Int($0)!})
var count = 0
for i in 0 ... a[0] {

    for j in 0 ... a[0] {
    if i + j > a[1] {
        break
    }
        if a[1] - i - j >= 0 && a[1] - i - j <= a[0] {
            count += 1
        }
    }
}
print(count)
