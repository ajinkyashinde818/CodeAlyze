def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    A = [i-1 for i in A]
    l = []
    v = set()
    t = 0
    while True:
        l.append(t)
        if t in v:
            break
        v.add(t)
        t = A[t]
    ll = len(l) - 1 - l.index(t)
    loop = l[l.index(t):-1]
    s = l.index(t)
    if K < len(l):
        return l[K] + 1
    K -= s
    K %= ll
    return loop[K] + 1
print(main())
