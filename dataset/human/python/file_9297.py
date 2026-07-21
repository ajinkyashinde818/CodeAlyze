import Foundation
let main: () = {
    
    let (N, K) = *listOfInt()
    let A = listOfInt(-1)
    var ans = 0
    if K < N {
        repeate(K) {
            ans = A[ans]
        }
        return print(ans + 1)
    }
    var M = [Int: Int]()
    var V = [Int]()
    for n in 0 ..< N {
        if M[ans] != nil { break }
        M[ans] = n
        V.append(ans)
        ans = A[ans]
    }
    let p = M[ans]!
    let res = M.count - p
    let index = p + ((K - p) % res)
    ans = V[index]
    
    print(ans + 1)

}()




















//----------------------------------

let dx = [1, 0, -1, 0] //[1, 0, -1, 0, -1,  1, -1, 1]
let dy = [0, 1, 0, -1] //[0, 1, 0, -1, -1, -1,  1, 1]

@inlinable func gcd(_ a: Int, _ b: Int) -> Int { (b > 0) ? gcd(b, a % b) : a }
@inlinable func lcm(_ a: Int, _ b: Int) -> Int { a / gcd(a, b) * b }

//----------------------------------

infix operator  =~ : ComparisonPrecedence
infix operator !=~ : ComparisonPrecedence
func =~ <T: FixedWidthInteger>(left: T, right: Range<T>) -> Bool { right ~= left }
func !=~ <T: FixedWidthInteger>(left: T, right: Range<T>) -> Bool { !(right ~= left) }
func =~ <T: FixedWidthInteger>(left: T, right: ClosedRange<T>) -> Bool { right ~= left }
func !=~ <T: FixedWidthInteger>(left: T, right: ClosedRange<T>) -> Bool { !(right ~= left) }

func =~ <T: Collection > (left: T.Element, right: T) -> Bool where T.Element : Equatable { right.contains(left) }
func !=~ <T: Collection > (left: T.Element, right: T) -> Bool where T.Element : Equatable { !right.contains(left) }

infix operator /^ : MultiplicationPrecedence
infix operator /^= : AssignmentPrecedence
func /^ <T: FixedWidthInteger>(left: T, right: T) -> T { (left + (right - 1)) / right }
func /^= <T: FixedWidthInteger>(left: inout T, right: T) { left = (left + (right - 1)) / right }

@inlinable func chmax<T: Comparable>(_ m: inout T, _ q: T) { if (m < q) { m = q } }
@inlinable func chmin<T: Comparable>(_ m: inout T, _ q: T) { if (m > q) { m = q } }
@inlinable func chRmax<T: Comparable>(_ m: inout T, _ q: T) -> Bool { if (m < q) { m = q; return true } else { return false } }
@inlinable func chRmin<T: Comparable>(_ m: inout T, _ q: T) -> Bool { if (m > q) { m = q; return true } else { return false } }

prefix operator *
prefix func * <T> (a: [T]) -> (T, T) { (a[0], a[1]) }
prefix func * <T> (a: [T]) -> (T, T, T) { (a[0], a[1], a[2]) }
prefix func * <T> (a: [T]) -> (T, T, T, T) { (a[0], a[1], a[2], a[3]) }
prefix func * <T> (a: [T]) -> (T, T, T, T, T) { (a[0], a[1], a[2], a[3], a[4]) }
prefix func * <T> (a: [T]) -> (T, T, T, T, T, T) { (a[0], a[1], a[2], a[3], a[4], a[5]) }

func printErr(_ str: String, terminator: String = "\n") {
    let s = str + terminator
    FileHandle.standardError.write(s.data(using: .utf8)!)
    FileHandle.standardError.synchronizeFile()
}

@inlinable func next() -> String { readLine()! }
@inlinable func nextInt() -> Int { Int(next())! }
@inlinable func nextDouble() -> Double { Double(next())! }
@inlinable func listOfString() -> [String] { next().split(separator: " ").map(String.init) }
@inlinable func listOfInt() -> [Int] { listOfString().map { Int($0)! } }
@inlinable func listOfInt(_ offset: Int = 0) -> [Int] { listOfString().map { Int($0)! + offset } }
@inlinable func listOfInt(_ offsets: Int ...) -> [Int] { listOfString().enumerated().map { Int($0.element)! + offsets[$0.offset % offsets.count] } }
@inlinable func listOfDouble(_ offset: Double = 0.0) -> [Double] { listOfString().map { Double($0)! + offset } }
@inlinable func listOfDouble(_ offsets: Double ...) -> [Double] { listOfString().enumerated().map { Double($0.element)! + offsets[$0.offset % offsets.count] } }

extension Int {
    init(s: String) { self.init(s)! }
    var isEven: Bool { self.isMultiple(of: 2) }
    var isOdd: Bool { !self.isEven }
    var isTrue: Bool { self != 0 }
    var isFalse: Bool { !self.isTrue }
    var toString: String { String(self) }
    var toChar: Character { Character(UnicodeScalar(UInt8(self))) }
}
func + (left: Int, right: Bool) -> Int { left + (right ? 1 : 0) }
extension Character {
    var asciiCode: Int { Int(self.asciiValue!) }
    var string: String { String(self) }
}
extension String {
    @inlinable subscript (position: Int) -> Character { self[self.index(self.startIndex, offsetBy: position)] }
    @inlinable func repeate(_ times: Int) -> String { String(repeating: self, count: times) }
    //  @inlinable subscript (n: Int) -> String { String(self[self.index(self.startIndex, offsetBy: n)]) }
    //  @inlinable subscript (n: Int) -> Int { Int(self[self.index(self.startIndex, offsetBy: n)].asciiValue!) }
    var toInt: Int { Int(self)! }
}
extension String { // VB like
    @inlinable func _index(_ position: Int) -> String.Index! {
        if !(0 ..< self.count ~= position) { return nil }
        return self.index(self.startIndex, offsetBy: position)
    }
    @inlinable func mid(from index: Int, length: Int) -> String! {
        if let startPosition = self._index(index) {
            if let endPosition = self._index(index + length - 1) {
                return String(self[startPosition...endPosition])
            } else {
                let endPosition = self.index(before: self.endIndex)
                return String(self[startPosition...endPosition])
            }
        }
        return ""
    }
    @inlinable func left(_ length: Int) -> String { String(self.prefix(length)) }
    @inlinable func right(_ length: Int) -> String { String(self.suffix(length)) }
}

extension Dictionary {
    @inlinable mutating func getOrSet(_ key: Key, _ defaultValue: () -> Value) -> Value {
        if let stored = self[key] { return stored }
        else {
            let newValue = defaultValue()
            self[key] = newValue
            return newValue
        }
    }
    @inlinable mutating func getOrElse(_ key: Key, _ defaultValue: () -> Value) -> Value {
        if let stored = self[key] { return stored } else { return defaultValue() }
    }
    @inlinable func containsKey(_ key: Key) -> Bool { self.keys.contains(key) }
}

extension Set {
    static func += (left: inout Set<Element>, right: Element) { left.insert(right) }
    static func -= (left: inout Set<Element>, right: Element) { left.remove(right) }
}

extension Array {
    static func += (left: inout Array<Element>, right: Element) { left.append(right) }
    init(_ size: Int, _ initValue: ((Int) -> Element)) {
        self = [Element]()
        for index in 0 ..< size {
            let value = initValue(index)
            self.append(value)
        }
    }
    init(_ size: Int, _ initValue: (() -> Element)) {
        self = [Element]()
        for _ in 0 ..< size {
            let value = initValue()
            self.append(value)
        }
    }
}
typealias IntArray = Array<Int>
typealias DoubleArray = Array<Double>
typealias BoolArray = Array<Bool>
typealias StringArray = Array<String>

extension Array where Element == Int {
    init(_ size: Int) {
        self = [Element](repeating: 0, count: size)
    }
}
extension Array where Element == Double {
    init(_ size: Int) {
        self = [Element](repeating: 0.0, count: size)
    }
}
extension Array where Element == Bool {
    init(_ size: Int) {
        self = [Element](repeating: false, count: size)
    }
}
extension Array where Element == String {
    init(_ size: Int) {
        self = [Element](repeating: "", count: size)
    }
}

extension Array {
    @inlinable func count(_ predicate: ((Element) -> Bool)) -> Int {
        var cnt = 0; for e in self { if (predicate(e)) { cnt += 1 } }
        return cnt
    }
    @inlinable func groupBy<K>(_ keySelector: (Element) -> K) -> [K : [Element]] {
        var destination = [K : [Element]]()
        for element in self {
            let key = keySelector(element)
            var list = destination.getOrSet(key) { [Element]() }
            list.append(element)
            destination[key] = list
        }
        return destination
    }
    @inlinable func groupByIndexed<K>(_ keySelector: (Element) -> K) -> [K : [Int]] {
        var destination = [K : [Int]]()
        for element in self.enumerated() {
            let key = keySelector(element.element)
            var list = destination.getOrSet(key) { [Int]() }
            list.append(element.offset)
            destination[key] = list
        }
        return destination
    }
}

extension Array {
    func binarySearch(_ element: Element, by compare: (Element, Element) -> Int, fromIndex: Int = 0, toIndex: Int = -1) -> Int {
        var low = fromIndex
        var high = (toIndex == -1) ? self.count - 1 : toIndex - 1
        while (low <= high) {
            let mid = (low + high) >> 1 // safe from overflows
            let midVal = self[mid]
            let cmp = compare(midVal, element)
            if (cmp < 0) { low = mid + 1 }          //-1
            else if (0 < cmp) { high = mid - 1 }    // 1
            else { return mid } // key found        // 0
        }
        return -(low + 1)  // key not found
    }
}
extension Array where Element : Comparable {
    func binarySearch(_ element: Element, fromIndex: Int = 0, toIndex: Int = -1) -> Int {
        var low = fromIndex
        var high = (toIndex == -1) ? self.count - 1 : toIndex - 1
        while (low <= high) {
            let mid = (low + high) >> 1 // safe from overflows
            let midVal = self[mid]
            if (midVal < element) { low = mid + 1 }
            else if (midVal > element) { high = mid - 1 }
            else { return mid } // key found
        }
        return -(low + 1)  // key not found
    }
}

extension Array where Element == Int {
    @inlinable func distinct() -> [Element] {
        var set = Set<Element>(), ary = [Element]()
        for n in self.indices { if !set.contains(self[n]) { ary.append(self[n]); set.insert(self[n]) } }
        return ary
    }
    @inlinable func any(_ predicate: (Element) -> Bool) -> Bool {
        var any = false; for element in self { if predicate(element) { any = true } }
        return any
    }
    @inlinable func all(_ predicate: (Element) -> Bool) -> Bool {
        self.allSatisfy(predicate)
    }
    @inlinable func sum() -> Element { self.reduce(0, +) }
    @inlinable func sum(by predicate: (Element) -> Element) -> Element {
        var sum = 0; for e in self { sum += predicate(e) }
        return sum
    }
    @inlinable func joinToString(_ sepatator: String = " ") -> String { self.map { String($0) }.joined(separator: sepatator) }
}

extension Array where Element == Double {
    @inlinable func sum() -> Element { self.reduce(0.0, +) }
    @inlinable func sum(by predicate: (Element) -> Element) -> Element {
        var sum = 0.0; for e in self { sum += predicate(e) }
        return sum
    }
    @inlinable func joinToString(_ sepatator: String = " ") -> String { self.map { String($0) }.joined(separator: sepatator) }
}
extension Array where Element == String {
    @inlinable func toIntDouble() -> (Int, Double) { (Int(self[0])!, Double(self[1])!) }
    @inlinable func toIntString() -> (Int, String) { (Int(self[0])!, self[1]) }
    @inlinable func toIntIntString() -> (Int, Int, String) { (Int(self[0])!, Int(self[1])!, self[2]) }
}

@inlinable func repeate(_ times1: Int, _ action: () -> Void) {
    for _ in 0 ..< times1 { action() }
}
@inlinable func repeate(_ times1: Int, _ action: (Int) -> Void) {
    for index1 in 0 ..< times1 {
        action(index1)
    }
}
@inlinable func repeate(_ times1: Int, _ times2: Int, _ action: (Int, Int) -> Void) {
    for index1 in 0 ..< times1 {
        for index2 in 0 ..< times2 {
            action(index1, index2)
        }
    }
}
@inlinable func repeate(_ times1: Int, _ times2: Int, _ times3: Int, _ action: (Int, Int, Int) -> Void) {
    for index1 in 0 ..< times1 {
        for index2 in 0 ..< times2 {
            for index3 in 0 ..< times3 {
                action(index1, index2, index3)
            }
        }
    }
}
@inlinable func repeate(_ times1: Int, _ times2: Int, _ times3: Int, _ times4: Int, _ action: (Int, Int, Int, Int) -> Void) {
    for index1 in 0 ..< times1 {
        for index2 in 0 ..< times2 {
            for index3 in 0 ..< times3 {
                for index4 in 0 ..< times4 {
                    action(index1, index2, index3, index4)
                }
            }
        }
    }
}

func measureTimeSeconds(block: (() -> Void)) -> Double {
    let startTime = Date()
    block()
    let duration = -startTime.timeIntervalSinceNow
    return duration
}

extension Array {
    func permutation (_ length: Int) -> [[Element]] {
        if length < 0 || length > self.count {
            return []
        } else if length == 0 {
            return [[]]
        } else {
            var permutations: [[Element]] = []
            let combinations = combination(length)
            for combination in combinations {
                var endArray: [[Element]] = []
                var mutableCombination = combination
                permutations += self.permutationHelper(length, array: &mutableCombination, endArray: &endArray)
            }
            return permutations
        }
    }
    private func permutationHelper(_ n: Int, array: inout [Element], endArray: inout [[Element]]) -> [[Element]] {
        if n == 1 {
            endArray += [array]
        }
        for i in 0  ..< n {
            _ = permutationHelper(n - 1, array: &array, endArray: &endArray)
            let j = n % 2 == 0 ? i : 0
            let temp: Element = array[j]
            array[j] = array[n - 1]
            array[n - 1] = temp
        }
        return endArray
    }
    /**
     - parameter length:
     - returns: Returns all of the combinations in the array of the given length
     */
    func combination (_ length: Int) -> [[Element]] {
        if length < 0 || length > self.count {
            return []
        }
        var indexes: [Int] = (0..<length).reduce([]) {$0 + [$1]}
        var combinations: [[Element]] = []
        let offset = self.count - indexes.count
        while true {
            var combination: [Element] = []
            for index in indexes {
                combination.append(self[index])
            }
            combinations.append(combination)
            var i = indexes.count - 1
            while i >= 0 && indexes[i] == i + offset {
                i -= 1
            }
            if i < 0 {
                break
            }
            i += 1
            let start = indexes[i-1] + 1
            for j in (i-1)..<indexes.count {
                indexes[j] = start + j - i + 1
            }
        }
        return combinations
    }
    /**
     - parameter length: The length of each permutations
     - returns: All of the permutations of this array of a given length, allowing repeats
     */
    func repeatedPermutation(_ length: Int) -> [[Element]] {
        if length < 1 {
            return []
        }
        var indexes: [[Int]] = []
        indexes.repeatedPermutationHelper([], length: length, arrayLength: self.count, indexes: &indexes)
        return indexes.map({ $0.map({ i in self[i] }) })
    }
    private func repeatedPermutationHelper(_ seed: [Int], length: Int, arrayLength: Int, indexes: inout [[Int]]) {
        if seed.count == length {
            indexes.append(seed)
            return
        }
        for i in (0..<arrayLength) {
            var newSeed: [Int] = seed
            newSeed.append(i)
            self.repeatedPermutationHelper(newSeed, length: length, arrayLength: arrayLength, indexes: &indexes)
        }
    }
}
