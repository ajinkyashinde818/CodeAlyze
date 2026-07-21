// 🐋💭
import Foundation

func readInts() -> [Int] {
    return readLine()!.split(separator: " ").map { Int($0)! }
}

func main() {
    let kn = readInts()
    let (k, n) = (kn[0],kn[1])
    let aryN = readInts()
    var ans = aryN[0] - aryN[n - 1] + k
    for i in 0..<n - 1 {
        ans = max(ans, aryN[i + 1] - aryN[i])
    }
    
    print(k - ans)
}

main()
