def resolve():
    N, M = [int(i) for i in input().split()]
    aabb = [list(map(int, input().split())) for _ in range(M)]
    to_N, from_1 = set(), set()
    for a, b in aabb:
        if b == N:
            to_N.add(a)
        elif a == 1:
            from_1.add(b)
    if len(to_N & from_1) > 0:
        print("POSSIBLE")
    else:
        print("IMPOSSIBLE")


resolve()
