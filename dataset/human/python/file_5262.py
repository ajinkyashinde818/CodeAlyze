def main():
    n, m = map(int, input().split())
    ship = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(lambda x: int(x) - 1, input().split())
        ship[a].append(b)
        ship[b].append(a)
    for i in range(1, n - 1):
        if 0 in ship[i] and n - 1 in ship[i]:
            print("POSSIBLE")
            break
    else:
        print("IMPOSSIBLE")


if __name__ == '__main__':
    main()
