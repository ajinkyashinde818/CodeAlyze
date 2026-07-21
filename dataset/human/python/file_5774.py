import Foundation
func readInts() -> [Int] {
    return readLine()!.split(separator: " ").map { Int($0)! }
}
let n=Int(readLine()!)!
var aa=readInts()
var bb=readInts()
var cc=readInts()
var before=40000
var ans=0
for a in aa{
  ans+=bb[a-1]
  if before==a-1{
    ans+=cc[a-2]
  }
  before=a
}
print(ans)
