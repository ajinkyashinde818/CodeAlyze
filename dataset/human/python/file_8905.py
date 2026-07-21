import Foundation

let targets: [String] = ["eraser", "erase", "dreamer", "dream"]


func main() {
	var input = readLine()!
	for i in 0..<targets.count {
		if input.isEmpty { break }
		input = input.replacingOccurrences(of: targets[i], with: "")
	}
	print(input.isEmpty ? "YES" : "NO")
}

main()
