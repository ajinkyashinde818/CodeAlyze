def main():
    n, m = map(int, input().split())
    ab = [list(map(int, input().split())) for _ in [0]*m]
    g = [[] for _ in [0]*n]
    [g[a-1].append(b-1) for a, b in ab]
    [g[b-1].append(a-1) for a, b in ab]

    q = [0]
    for _ in range(2):
        q2 = []
        while q:
            i = q.pop()
            for j in g[i]:
                q2.append(j)
        q = q2
    if n-1 in q:
        print("POSSIBLE")
    else:
        print("IMPOSSIBLE")


main()
