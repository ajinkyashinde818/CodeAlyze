def main():
    n = int(raw_input())
    a = map(int, raw_input().split())
    s = sum(a)
    t = n * (n + 1) / 2
    if s % t:
        print "NO"
        return
    t = s / t
    a += [a[0]]
    b = [a[i+1] - a[i] - t for i in xrange(n)]
    c = [0] * (n + n)
    d = [0] * (n + n)
    for i, x in enumerate(b):
        if x % n:
            print "NO"
            return
        b[i] = -x / n
        c[i+n] += b[i]
    b += [0] * n
    k = 0
    s = 0
    for i in xrange(n + n):
        k += b[i]
        d[i] += s if s > 0 else 0
        s += k
        k -= c[i]
        s -= c[i] * (n + 1)
    for i in xrange(n):
        if a[i] != d[i] + d[i+n]:
            print "NO"
            return
    print "YES"
main()
