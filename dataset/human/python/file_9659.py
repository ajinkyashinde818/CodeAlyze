def main():
    n, k = map(int, input().split())
    As = list(map(int, input().split()))
    i = 0
    visit = [0]*n
    move = []
    roop = []
    while visit[i] != 2:
        if visit[i] == 0:
            move.append(i)
        else:
            roop.append(i)
        visit[i] += 1
        i = As[i] - 1

    if len(move) > k:
        ans = move[k] + 1
    else:
        ans = roop[(k-(len(move)-len(roop))) % len(roop)]+1
    print(ans)


if __name__ == "__main__":
    main()
