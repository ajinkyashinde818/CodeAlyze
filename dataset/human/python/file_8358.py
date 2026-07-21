import Foundation

let input = readLine()!.componentsSeparatedByString(" ")
let array = readLine()!.componentsSeparatedByString(" ").map{ Int($0)! }
var N = 0
var maxDis = 0
for e in array{
  let dist = e - N
  if(dist > maxDis){
    maxDis = dist
  }
  N = e
}
let around = Int(input[0])!
if(around - N + array[0] > maxDis){
  maxDis = around - N + array[0]
}
print(around - maxDis)
