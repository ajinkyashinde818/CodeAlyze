def solve():
    N, M = [int(x) for x in input().split()]

    from_1 = set()
    to_N = set()
    for i in range(M):
        u, v = [int(x) for x in input().split()]

        if u == 1:
            from_1.add(v)

        if v == N:
            to_N.add(u)

    ss = from_1.intersection(to_N)
    return len(ss) != 0


def main():
    ans = solve()
    if ans:
        print("POSSIBLE")
    else:
        print("IMPOSSIBLE")


if __name__ == '__main__':
    main()
