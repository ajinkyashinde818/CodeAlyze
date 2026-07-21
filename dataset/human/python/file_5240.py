def solve(N, M, ABs):
    from1 = set()
    toN = set()
    for a, b in ABs:
        a, b = min(a, b), max(a, b)
        if a == 1:
            from1.add(b)
        if b == N:
            toN.add(a)
    return "POSSIBLE" if len(from1.intersection(toN)) else "IMPOSSIBLE"

if __name__ == "__main__":
    N, M = map(int, input().split(" "))
    ABs = [tuple(map(int, input().split(" "))) for _ in range(M)]
    print(solve(N, M, ABs))
