import Foundation
//最大公約数を求める関数
func gcd(_ num1: Int, _ num2: Int) -> Int {
   let r = num1 % num2
   if r != 0 {
       return gcd(num2, r)
   } else {
       return num2
   }
}
//３つ以上の数の最大公約数を求める
func gcdArr(_ numArr: [Int]) -> Int {
    var ans: Int = numArr[0]
    for i in numArr {
        ans = gcd(ans, i)
    }
    return ans
}

//最小公倍数を求める関数
func lcm(_ num1: Int, _ num2: Int) -> Int {
    
    var gcdNum = gcd(num1, num2)
    return num1*num2/gcdNum
}

let rdInt = readLine()!.split(separator: " ").map({Int($0)!})
let a = rdInt[0]
let b = rdInt[1]
print(lcm(a, b))
