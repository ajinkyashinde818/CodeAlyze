def main():
    n, k = map(int, input().split())
    a = [int(i) - 1 for i in input().split()]
    s = 0
    m, l = 0, 0
    p = []
    h = set()
    for _ in range(n):
        p.append(s)
        h.add(s)
        s = a[s]
        if s in h:
            m = p.index(s)
            l = len(h) - m
            break
    if k <= m:
        print(p[k] + 1)
    else:
        print(p[(k - m) % l + m] + 1)

if __name__ == '__main__':
    main()
