import Foundation

func readInts() -> [Int] {
    return readLine()!.split(separator: " ").map { Int($0)! }
}

let n:Int=Int(readLine()!)!
let a=readInts()
let b=readInts()
let c=readInts()
var ans=0

for i in 0..<n{ans+=b[i]}

for i in 0..<n-1{if a[i+1]-a[i]==1 {ans+=c[a[i]-1]}}


print(ans)
