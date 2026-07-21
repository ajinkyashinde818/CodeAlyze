// 🐋💭 Next Prime
import Foundation

func readInts() -> [Int] {
    return readLine()!.split(separator: " ").map { Int($0)! }
}

func readInt() -> Int {
    return Int(readLine()!)!
}

func gcd(_ m:Int, _ n:Int) -> Int {
    if n == 0 {return m}
    return gcd(n, m % n)
}

func main() {
    let ab = readInts()
    let (a, b) = (ab[0], ab[1])
    let gcdValue = gcd(a, b)
    print(gcdValue * (a / gcdValue) * (b / gcdValue))
}
main()
