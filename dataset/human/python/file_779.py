import Foundation
 
let input_line: String = readLine()!
let split: [String] = input_line.components(separatedBy: " ")
 
let N = Int(split[0])!
let R = Int(split[1])!

if (N <= 10){
    print(R+100*(10-N))
}else{
    print(R)
}
