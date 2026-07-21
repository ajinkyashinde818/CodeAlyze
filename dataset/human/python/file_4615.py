let (N, Q) = getIntPair()
let A = getInts(count: N)

struct ARange {
    let ones, zeros: Int
    let inversion, revInversion: Int
    init() {
        (ones, zeros) = (0, 0)
        (inversion, revInversion) = (0, 0)
    }
    init(_ a: Int) {
        (ones, zeros) = (a, a^1)
        (inversion, revInversion) = (0, 0)
    }
    init(_ a: ARange, _ b: ARange) {
        ones = a.ones + b.ones
        zeros = a.zeros + b.zeros
        inversion = a.inversion + b.inversion + (a.ones * b.zeros)
        revInversion = a.revInversion + b.revInversion + (b.ones * a.zeros)
    }
    init(_ a: ARange, flip: Bool) {
        if !flip {
            self = a
        } else {
            ones = a.zeros
            zeros = a.ones
            inversion = a.revInversion
            revInversion = a.inversion
        }
    }
}

var st = SegmentTree<ARange, Bool>(
    count: N,
    zero: ARange(),
    combine: ARange.init,
    update: ARange.init,
    updateDistributive: { x, flip, _ in ARange.init(x, flip: flip) },
    updateComposition: { $0 ^ $1 }
)
for (i, a) in A.enumerated() {
    st.set(point: i, to: ARange(a))
}

var responses = [Int]()
for _ in 0..<Q {
    switch getIntTriplet() {
    case let (1, L, R):
        st.update(range: (L-1)...(R-1), by: true)
    case let (2, L, R):
        responses.append(st.query(range: (L-1)...(R-1)).inversion)
    default:
        fatalError("Input parse error")
    }
}
print(responses.map(String.init).joined(separator: "\n"))




//=============================================================================
// MARK: - SegmentTree.swift
// code section by Barry Fam

struct SegmentTree<Element, Update> {
    let count: Int
    let zero: Element
    let lazy: Bool

    let combine: (Element, Element) -> Element
    let update: (Element, Update) -> Element
    let updateDistributive: ((Element, Update, Int) -> Element)?
    let updateComposition: ((Update, Update) -> Update)?

    private var tree: [Element]
    private var pending: [Update?]

    init(count: Int,
         zero: Element,
         combine: @escaping (Element, Element) -> Element,
         update: @escaping (Element, Update) -> Element,
         updateDistributive: ((Element, Update, Int) -> Element)? = nil,
         updateComposition: ((Update, Update) -> Update)? = nil
    ){
        let count = 1 << (count-1).bitLength
        self.count = count
        self.zero = zero
        self.lazy = updateDistributive != nil && updateComposition != nil

        self.combine = combine
        self.update = update
        self.updateDistributive = updateDistributive
        self.updateComposition = updateComposition

        tree = Array(repeating: zero, count: count*2)
        if self.lazy == true {
            pending = Array(repeating: nil, count: count)
        } else {
            pending = []
        }
    }

    // MARK: - Private methods

    /// The number of leaf nodes covered by tree index `u`
    private func segmentLength(u: Int) -> Int {
        1 << (count.bitLength - u.bitLength)
    }

    // MARK: Node modification

    /// Update tree index `u` as if its child leaves had been updated with `update`, without actually traversing down to them
    private mutating func lazyUpdate(u: Int, by value: Update) {
        tree[u] = updateDistributive!(tree[u], value, segmentLength(u: u))
        if u < count {
            if let p = pending[u] {
                pending[u] = updateComposition!(p, value)
            } else {
                pending[u] = value
            }
        }
    }

    /// Apply any pending update at tree index `u` to its two immediate children
    private mutating func push1(u: Int) {
        if let update = pending[u] {
            lazyUpdate(u: u<<1, by: update)
            lazyUpdate(u: u<<1|1, by: update)
            pending[u] = nil
        }
    }

    /// (Re)calculate tree index `u` by `combine()` of its two immediate children
    private mutating func build1(u: Int) {
        push1(u: u)
        tree[u] = combine(tree[u<<1], tree[u<<1|1])
    }

    // MARK: Node-set modification

    /// Push lazy update from root to raw index `i`
    private mutating func pushPath(i: Int) {
        let u = i + count
        for s in (1 ..< u.bitLength).reversed() {
            push1(u: u >> s)
        }
    }

    /// Update tree nodes from raw index `i` to root
    private mutating func buildPath(i: Int) {
        var u = i + count
        while u > 1 {
            u >>= 1
            build1(u: u)
        }
    }

    // MARK: - Public methods

    mutating func set(point: Int, to value: Element) {
        let i = point
        if lazy { pushPath(i: i) }
        tree[i + count] = value
        buildPath(i: i)
    }

    mutating func update(range: Range<Int>, by value: Update) {
        precondition(range.count == 1 || lazy, "Range update requires lazy propagation")

        // push in case of non-commutative update operator
        let (i, j) = (range.lowerBound, range.upperBound)
        if lazy {
            pushPath(i: i)
            pushPath(i: j-1)
        }

        // write cover nodes
        var (l, r) = (i+count, j+count)
        while l < r {
            if l&1 == 1 {
                lazyUpdate(u: l, by: value)
                l += 1
            }
            if r&1 == 1 {
                r -= 1
                lazyUpdate(u: r, by: value)
            }
            l >>= 1
            r >>= 1
        }

        // build
        buildPath(i: i)
        buildPath(i: j-1)
    }
    mutating func update(range: ClosedRange<Int>, by value: Update) {
        update(range: Range(range), by: value)
    }
    mutating func update(point: Int, by value: Update) {
        update(range: point...point, by: value)
    }

    mutating func query(range: Range<Int>) -> Element {
        // push
        let (i, j) = (range.lowerBound, range.upperBound)
        if lazy {
            pushPath(i: i)
            pushPath(i: j-1)
        }

        // read cover nodes
        var (l, r) = (i+count, j+count)
        var lReduce, rReduce: Element?
        while l < r {
            if l&1 == 1 {
                lReduce = lReduce != nil ? combine(lReduce!, tree[l]) : tree[l]
                l += 1
            }
            if r&1 == 1 {
                r -= 1
                rReduce = rReduce != nil ? combine(tree[r], rReduce!) : tree[r]
            }
            l >>= 1
            r >>= 1
        }
        if lReduce == nil {
            return rReduce!
        } else if rReduce == nil {
            return lReduce!
        } else {
            return combine(lReduce!, rReduce!)
        }
    }
    mutating func query(range: ClosedRange<Int>) -> Element {
        query(range: Range(range))
    }
    mutating func query(point: Int) -> Element {
        query(range: point...point)
    }
}

//=============================================================================
// MARK: - contestIO.swift
// code section by Barry Fam

#if os(Linux)
import Glibc
#else
import Darwin.C
#endif

struct IO {
    static var INPUT = stdin
    fileprivate static var buffer: UnsafeMutablePointer<CChar>?
    fileprivate static var bufferCapacity: Int32 = 0
}

fileprivate func getsToBuffer(size: Int32) -> UnsafeMutablePointer<CChar> {
    if IO.bufferCapacity < size {
        IO.buffer?.deallocate()
        IO.buffer = UnsafeMutablePointer.allocate(capacity: Int(size))
        IO.bufferCapacity = size
    }
    return fgets(IO.buffer!, size, IO.INPUT)
}
fileprivate func getIntFromBuffer(_ ptr: inout UnsafeMutablePointer<CChar>) -> Int {
    var minus = false
    var x: Int?
    while true {
        switch ptr.pointee {
        case 0x2D:
            assert(!minus && x == nil)
            minus = true
        case let d where 0x30...0x39 ~= d:
            x = (x ?? 0)*10 + Int(d)-0x30
        default:
            if x != nil { return minus ? -x! : x! }
            assert(ptr.pointee == 0x20)
        }
        ptr += 1
    }
}

func getString(maxLength: Int) -> String {
    var s = String(cString: getsToBuffer(size: Int32(maxLength + 3)))
    if s.last == "\n" { s.removeLast() }
    if s.last == "\r" { s.removeLast() }
    return s
}
func getStringAsArray(maxLength: Int) -> [UInt8] {
    let ptr = getsToBuffer(size: Int32(maxLength + 3))
    var s = [UInt8]()
    for ptr in ptr ..< ptr + maxLength {
        let c = UInt8(ptr.pointee)
        if c == 0x00 || c == 0x0A || c == 0x0D { break }
        s.append(c)
    }
    return s
}
func getInt() -> Int {
    var xPtr = getsToBuffer(size: 24)
    return getIntFromBuffer(&xPtr)
}
func getIntPair() -> (Int, Int) {
    var xPtr = getsToBuffer(size: 2*24)
    let x1 = getIntFromBuffer(&xPtr)
    let x2 = getIntFromBuffer(&xPtr)
    return (x1, x2)
}
func getIntTriplet() -> (Int, Int, Int) {
    var xPtr = getsToBuffer(size: 3*24)
    let x1 = getIntFromBuffer(&xPtr)
    let x2 = getIntFromBuffer(&xPtr)
    let x3 = getIntFromBuffer(&xPtr)
    return (x1, x2, x3)
}
func getIntQuadruplet() -> (Int, Int, Int, Int) {
    var xPtr = getsToBuffer(size: 4*24)
    let x1 = getIntFromBuffer(&xPtr)
    let x2 = getIntFromBuffer(&xPtr)
    let x3 = getIntFromBuffer(&xPtr)
    let x4 = getIntFromBuffer(&xPtr)
    return (x1, x2, x3, x4)
}
func getIntQuintuplet() -> (Int, Int, Int, Int, Int) {
    var xPtr = getsToBuffer(size: 5*24)
    let x1 = getIntFromBuffer(&xPtr)
    let x2 = getIntFromBuffer(&xPtr)
    let x3 = getIntFromBuffer(&xPtr)
    let x4 = getIntFromBuffer(&xPtr)
    let x5 = getIntFromBuffer(&xPtr)
    return (x1, x2, x3, x4, x5)
}
func getIntSextuplet() -> (Int, Int, Int, Int, Int, Int) {
    var xPtr = getsToBuffer(size: 6*24)
    let x1 = getIntFromBuffer(&xPtr)
    let x2 = getIntFromBuffer(&xPtr)
    let x3 = getIntFromBuffer(&xPtr)
    let x4 = getIntFromBuffer(&xPtr)
    let x5 = getIntFromBuffer(&xPtr)
    let x6 = getIntFromBuffer(&xPtr)
    return (x1, x2, x3, x4, x5, x6)
}
func getInts(count: Int) -> [Int] {
    var xPtr = getsToBuffer(size: Int32(count) * 24)
    var a = [Int]()
    a.reserveCapacity(count)
    for _ in 0..<count { a.append(getIntFromBuffer(&xPtr)) }
    return a
}

//=============================================================================
// MARK: - operators.swift
// code section by Barry Fam

infix operator <?= : AssignmentPrecedence
infix operator >?= : AssignmentPrecedence
func <?= <T: Comparable>(lhs: inout T, rhs: T) {
    if lhs < rhs { lhs = rhs }
}
func >?= <T: Comparable>(lhs: inout T, rhs: T) {
    if lhs > rhs { lhs = rhs }
}

infix operator ??= : AssignmentPrecedence
func ??= <T>(lhs: inout T?, rhs: T?) {
    if lhs == nil { lhs = rhs }
}

func ^ (lhs: Bool, rhs: Bool) -> Bool {
    lhs != rhs
}

func + <T: AdditiveArithmetic>(u: (T, T), v: (T, T)) -> (T, T) {
    (u.0+v.0, u.1+v.1)
}
func + <T: AdditiveArithmetic>(u: (T, T, T), v: (T, T, T)) -> (T, T, T) {
    (u.0+v.0, u.1+v.1, u.2+v.2)
}
func + <T: AdditiveArithmetic>(u: (T, T, T, T), v: (T, T, T, T)) -> (T, T, T, T) {
    (u.0+v.0, u.1+v.1, u.2+v.2, u.3+v.3)
}
func + <T: AdditiveArithmetic>(u: (T, T, T, T, T), v: (T, T, T, T, T)) -> (T, T, T, T, T) {
    (u.0+v.0, u.1+v.1, u.2+v.2, u.3+v.3, u.4+v.4)
}
func + <T: AdditiveArithmetic>(u: (T, T, T, T, T, T), v: (T, T, T, T, T, T)) -> (T, T, T, T, T, T) {
    (u.0+v.0, u.1+v.1, u.2+v.2, u.3+v.3, u.4+v.4, u.5+v.5)
}

func - <T: AdditiveArithmetic>(u: (T, T), v: (T, T)) -> (T, T) {
    (u.0-v.0, u.1-v.1)
}
func - <T: AdditiveArithmetic>(u: (T, T, T), v: (T, T, T)) -> (T, T, T) {
    (u.0-v.0, u.1-v.1, u.2-v.2)
}
func - <T: AdditiveArithmetic>(u: (T, T, T, T), v: (T, T, T, T)) -> (T, T, T, T) {
    (u.0-v.0, u.1-v.1, u.2-v.2, u.3-v.3)
}
func - <T: AdditiveArithmetic>(u: (T, T, T, T, T), v: (T, T, T, T, T)) -> (T, T, T, T, T) {
    (u.0-v.0, u.1-v.1, u.2-v.2, u.3-v.3, u.4-v.4)
}
func - <T: AdditiveArithmetic>(u: (T, T, T, T, T, T), v: (T, T, T, T, T, T)) -> (T, T, T, T, T, T) {
    (u.0-v.0, u.1-v.1, u.2-v.2, u.3-v.3, u.4-v.4, u.5-v.5)
}

infix operator *+ : MultiplicationPrecedence
func *+ <T: Numeric>(u: (T, T), v: (T, T)) -> T {
    var x = u.0 * v.0
    x += u.1 * v.1
    return x
}
func *+ <T: Numeric>(u: (T, T, T), v: (T, T, T)) -> T {
    var x = u.0 * v.0
    x += u.1 * v.1
    x += u.2 * v.2
    return x
}
func *+ <T: Numeric>(u: (T, T, T, T), v: (T, T, T, T)) -> T {
    var x = u.0 * v.0
    x += u.1 * v.1
    x += u.2 * v.2
    x += u.3 * v.3
    return x
}
func *+ <T: Numeric>(u: (T, T, T, T, T), v: (T, T, T, T, T)) -> T {
    var x = u.0 * v.0
    x += u.1 * v.1
    x += u.2 * v.2
    x += u.3 * v.3
    x += u.4 * v.4
    return x
}
func *+ <T: Numeric>(u: (T, T, T, T, T, T), v: (T, T, T, T, T, T)) -> T {
    var x = u.0 * v.0
    x += u.1 * v.1
    x += u.2 * v.2
    x += u.3 * v.3
    x += u.4 * v.4
    x += u.5 * v.5
    return x
}

extension BinaryInteger {
    func ceilDiv(by d: Self) -> Self {
        assert(self >= 0)
        return (self + d-1) / d
    }
}

func gcd<T: BinaryInteger>(_ a: T, _ b: T) -> T {
    b == 0 ? a : gcd(b, a%b)
}
func lcm<T: BinaryInteger>(_ a: T, _ b: T) -> T {
    a / gcd(a, b) * b
}

extension FixedWidthInteger {
    var bitLength: Int {
        assert(self >= 0)
        return self.bitWidth - self.leadingZeroBitCount
    }
}
