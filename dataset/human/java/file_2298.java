import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

class LazySegTree<Monoid, F>(private val n: Int, private val op: (Monoid, Monoid) -> Monoid, private val e: Monoid, private val mapping: (F, Monoid) -> Monoid, private val composition: (F, F) -> F, private val id: F) : Iterable<Monoid> {
    private var d: MutableList<Monoid>
    private var lz: MutableList<F>
    private var size = 1
    private var log = 0

    init {
        while (size < n) {
            size *= 2
            log++
        }
        d = MutableList(2 * size) { e }
        lz = MutableList(size) { id }
    }

    constructor(a: Array<Monoid>, op: (Monoid, Monoid) -> Monoid, e: Monoid, mapping: (F, Monoid) -> Monoid, composition: (F, F) -> F, id: F) : this(a.count(), op, e, mapping, composition, id) {
        for (i in 0 until n) {
            d[size + i] = a[i]
        }
        for (i in size - 1 downTo 1) {
            update(i)
        }
    }

    operator fun set(p: Int, x: Monoid) {
        if (p !in 0 until n) {
            throw Exception()
        }
        val p1 = p + size
        for (i in log downTo 1) {
            push(p1 shr i)
        }
        d[p1] = x
        for (i in 1..log) {
            update(p1 shr i)
        }
    }

    operator fun get(p: Int): Monoid {
        if (p !in 0 until n) {
            throw Exception()
        }
        val p1 = p + size
        for (i in log downTo 1) {
            push(p1 shr i)
        }
        return d[p1]
    }

    fun prod(l: Int, r: Int): Monoid {
        if (l !in 0..r || r !in l..n) {
            throw Exception()
        }
        if (l == r) return e
        var l1 = l + size
        var r1 = r + size
        for (i in log downTo 1) {
            if ((l1 shr i) shl i != l1) push(l1 shr i)
            if ((r1 shr i) shl i != r1) push(r1 shr i)
        }
        var sml = e
        var smr = e
        while (l1 < r1) {
            if (l1 and 1 != 0) sml = op(sml, d[l1++])
            if (r1 and 1 != 0) smr = op(d[--r1], smr)
            l1 /= 2
            r1 /= 2
        }
        return op(sml, smr)
    }

    fun allProd(): Monoid {
        return d[1]
    }

    fun apply(p: Int, f: F) {
        if (p !in 0 until n) {
            throw Exception()
        }
        val p1 = p + size
        for (i in log downTo 1) {
            push(p1 shr i)
        }
        d[p1] = mapping(f, d[p1])
        for (i in 1..log) {
            update(p1 shr i)
        }
    }

    fun apply(l: Int, r: Int, f: F) {
        if (l !in 0..r || r !in l..n) {
            throw Exception()
        }
        if (l == r) return
        var l1 = l + size
        var r1 = r + size
        for (i in log downTo 1) {
            if ((l1 shr i) shl i != l1) push(l1 shr i)
            if ((r1 shr i) shl i != r1) push((r1 - 1) shr i)
        }
        val l2 = l1
        val r2 = r1
        while (l1 < r1) {
            if (l1 and 1 != 0) allApply(l1++, f)
            if (r1 and 1 != 0) allApply(--r1, f)
            l1 /= 2
            r1 /= 2
        }
        l1 = l2
        r1 = r2
        for (i in 1..log) {
            if ((l1 shr i) shl i != l1) update(l1 shr i)
            if ((r1 shr i) shl i != r1) update((r1 - 1) shr i)
        }
    }

    fun maxRight(l: Int, g: (Monoid) -> Boolean): Int {
        if (l !in 0..n || !g(e)) {
            throw Exception()
        }
        if (l == n) return n
        var l1 = l + size
        for (i in log downTo 1) push(l1 shr i)
        var sm = e
        do {
            while (l1 % 2 == 0) l1 /= 2
            if (!g(op(sm, d[l1]))) {
                while (l1 < size) {
                    push(l1)
                    l1 *= 2
                    if (g(op(sm, d[l1]))) {
                        sm = op(sm, d[l1])
                        l1++
                    }
                }
                return l1 - size
            }
            sm = op(sm, d[l1])
            l1++
        } while ((l1 and -l1) != l1)
        return n
    }

    fun minLeft(r: Int, g: (Monoid) -> Boolean): Int {
        if (r !in 0..n || !g(e)) {
            throw Exception()
        }
        if (r == 0) return 0
        var r1 = r + size
        for (i in log downTo 1) push((r1 - 1) shr i)
        var sm = e
        do {
            r1--
            while (r1 > 1 && r1 % 2 != 0) r1 /= 2
            if (!g(op(d[r1], sm))) {
                while (r1 < size) {
                    push(r1)
                    r1 = 2 * r1 + 1
                    if (g(op(d[r1], sm))) {
                        sm = op(d[r1], sm)
                        r1--
                    }
                }
                return r1 + 1 - size
            }
            sm = op(d[r1], sm)
        } while ((r1 and -r1) != r1)
        return 0
    }

    private fun update(k: Int) {
        d[k] = op(d[2 * k], d[2 * k + 1])
    }

    private fun allApply (k: Int, f: F) {
        d[k] = mapping(f, d[k])
        if (k < size) {
            lz[k] = composition(f, lz[k])
        }
    }

    private fun push(k: Int) {
        allApply(2 * k, lz[k])
        allApply(2 * k + 1, lz[k])
        lz[k] = id
    }

    override fun iterator(): Iterator<Monoid> {
        return (0 until n).map { this[it] }.iterator()
    }
}

data class S(val zero: Long, val one: Long, val inversion: Long)

fun op(l: S, r: S): S {
    return S(l.zero + r.zero, l.one + r.one, l.inversion + r.inversion + l.one * r.zero)
}

fun mapping(l: Boolean, r: S): S {
    if (!l) return r
    return S(r.one, r.zero, r.one * r.zero - r.inversion)
}

fun composition(l: Boolean, r: Boolean): Boolean {
    return (l and !r) or (!l and r)
}

fun PrintWriter.solve(sc: FastScanner) {
    val e = S(0, 0, 0)
    val id = false
    val n = sc.nextInt()
    val q = sc.nextInt()
    val a = Array(n) { sc.nextInt() }
    val b = a.map { if (it == 0) S(1, 0, 0) else S(0, 1, 0) }.toTypedArray()
    val seg = LazySegTree(b, ::op, e, ::mapping, ::composition, id)
    for (i in 0 until q) {
        val t = sc.nextInt()
        val l = sc.nextInt() - 1
        val r = sc.nextInt()
        if (t == 1) {
            seg.apply(l, r, true)
        } else {
            println(seg.prod(l, r).inversion)
        }
    }
}

fun main() {
    val writer = PrintWriter(System.out, false)
    writer.solve(FastScanner(System.`in`))
    writer.flush()
}

class FastScanner(s: InputStream) {
    private var st = StringTokenizer("")
    private val br = BufferedReader(InputStreamReader(s))

    fun next(): String {
        while (!st.hasMoreTokens()) st = StringTokenizer(br.readLine())

        return st.nextToken()
    }

    fun nextInt() = next().toInt()
    fun nextLong() = next().toLong()
    fun nextLine() = br.readLine()
    fun nextDouble() = next().toDouble()
    fun ready() = br.ready()
}
