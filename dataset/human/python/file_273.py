import Foundation

let N = Int(readLine()!)!
let A = readLine()!.split(separator: " ").map { Int($0)! }

let absolutes = A.map { abs($0) }
let sum = absolutes.reduce(0, +)
let min = absolutes.min()!
let isEven = A.filter({ $0.signum() == -1 }).count % 2 == 0

let answer = isEven ? sum : sum - min * 2

print(answer)
