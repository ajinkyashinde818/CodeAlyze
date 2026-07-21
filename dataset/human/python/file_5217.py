def main():
    n, m = map(int, input().split())

    islands_to_1 = [0 for _ in range(n+1)]
    islands_to_n = []
    for _ in range(m):
        boat = list(map(int, input().split()))
        if 1 in boat:
            islands_to_1[boat[1]] = 1

        if n in boat:
            islands_to_n.append(min(boat))

    for island_to_n in islands_to_n:
        if islands_to_1[island_to_n] == 1:
            print("POSSIBLE")
            return

    print("IMPOSSIBLE")
    return


if __name__ == "__main__":
    main()
