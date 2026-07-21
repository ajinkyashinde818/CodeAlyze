def main():
    DOUBLING_ROWS = 60  # 2**60 > 10**18
    n, k = [int(x) for x in input().split()]
    table = []  # [start][teleporting]
    table_append = table.append
    table_append([int(x) - 1 for x in input().split()])  # 2**0 teleport
    for _ in range(DOUBLING_ROWS):
        pre = table[-1]
        table_append([pre[x] for x in pre])
    now = 0
    for i, row in enumerate(table):
        if ((1 << i) & k) > 0:
            now = row[now]
    return now + 1


if __name__ == '__main__':
    print(main())
