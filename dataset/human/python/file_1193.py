// 🐋💭
import Foundation

func readInts() -> [Int] {
    return readLine()!.split(separator: " ").map { Int($0)! }
}

func readInt() -> Int {
    return Int(readLine()!)!
}

func readDoubles () -> [Double] {
    return readLine()!.split(separator: " ").map { Double($0)! }
}

func readDouble() -> Double{
    return Double(readLine()!)!
}

func readLines() -> [String] {
    return readLine()!.map { String($0) }
}
///最大公約数を返す
func gcd(_ m:Int, _ n:Int) -> Int {
    if n == 0 {return m}
    return gcd(n, m % n)
}

///最大公約数を返す
func gcd(_ array: [Int]) -> Int {
    var value = array[0]
    if array.count > 1 {
        for i in 1..<array.count {
            value = gcd(value, array[i])
        }
    }
    return value
}

///最小公倍数を返す
func lcm(_ m:Int, _ n:Int) -> Int {
    let g = gcd(m, n)
    return m / g * n
}

///素数判定(試し割り)
func isPrime(_ x:Int) -> Bool {
    if x <= 1 || x % 2 == 0 { return false }
    if x == 2 { return true }
    for i in stride(from: 3, to: Int(ceil(sqrt(Double(x)))), by: 2){
        if x % i == 0 {
            return false
        }
    }
    return true
}

//https://program-life.com/669
///実行速度の計測
func exectionTime(action: () -> Void) {
    let startDate = Date()
    action()
    let endDate = Date()
    print(endDate.timeIntervalSince(startDate))
}

//https://riptutorial.com/ja/swift/example/14738/インデックスを知らずに配列から要素を削除する
extension Array where Element: Equatable {
    
    mutating func remove(_ element: Element) {
        _ = firstIndex(of: element).flatMap {
            self.remove(at: $0)
        }
    }
}

func binarySearch(rifgt:Int, key:Int, ary:[String]) -> Int{
    var left = 0
    var right = rifgt
    
    while abs(right - left) > 1 {
        let mid = left + (right - left) / 2
        
        if Int(ary[mid])! < key {
            left = mid
            
        } else {
            right = mid
        }
    }
    return left
}

func arrangement (prev:String, ary:[String], returnVal:[String]) -> [String] {
    var returnVal = returnVal
    if ary.count == 0 {
        returnVal.append(prev)
        return returnVal
    }
    
    for s in ary {
        let wprev = prev + s
        var wary = ary
        wary.remove(s)
        returnVal = arrangement(prev: wprev, ary: wary, returnVal: returnVal)
    }
    return returnVal
}
// https://algo-logic.info/divisor/
/// 約数の配列を返す
func divisor(_ n:Int) -> [Int] {
    var ret = [Int]()
    var i = 1
    while i * i <= n {
        if n % i == 0 {
            ret.append(i)
            if i * i != n {
                ret.append(n / i)
            }
        }
        i += 1
    }
    return ret.sorted()
}

/// 1〜nまでの数字からなる辞書順列のm番目の順列を返す
func permutation(_ n: Int, _ m: Int) -> [Int] {
    var m = m
    
    var temp = [Int](repeating: 0, count: n)
    var surplus = [Int](repeating: 0, count: n)
    
    for i in 1...n {
        temp[i - 1] = i
        
        surplus[n - i] = m % i
        m = m / i
    }
    
    var order = [Int](repeating: 0, count: n)
    
    for i in 0..<n {
        order[i] = temp[surplus[i]]
        var j = surplus[i]
        while j + 1 < n {
            temp[j] = temp[j + 1]
            j += 1
        }
    }
    return order
}

func main() {
    let N = readInt()
    let a = readInts()
    //＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿ここまで入力
    var (x, y) = (a[0], a.reduce(0) { $0 + $1 } - a[0])
    var ans = abs(x - y)
    var cnt = 1
    while cnt < N - 1 {
        ans = min(ans, abs(x - y))
        x += a[cnt]
        y -= a[cnt]
        
        cnt += 1
        
    }
    print(ans)
}
main()
