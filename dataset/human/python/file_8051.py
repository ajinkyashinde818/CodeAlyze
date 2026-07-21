import Foundation

var input_lines = [String]()
input_lines.append(readLine()!)
let strings = input_lines[0].componentsSeparatedByString(" ")

let K = (Int)(strings[0])!
let S = (Int)(strings[1])!

var counter = 0

for i in 0...K {
    if (S - i) > (K * 2) {
        continue
    }
    for j in 0...K {
        let k = (S - i - j)
        
        if 0 <= k && k <= K {
            counter += 1
        }
    }
}

print(counter)
