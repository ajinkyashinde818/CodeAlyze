def match(start_x, start_y):
    count = 0
    for x in range(m):
        for y in range(m):
            if a[start_x+x][start_y+y] == b[x][y]:
                count += 1

    return count // m**2


def main():
    count_match = 0
    for x in range(n - m + 1):
        for y in range(n - m + 1):
            count_match += match(x, y)

    if count_match != 0:
        print("Yes")
    else:
        print("No")


if __name__ == '__main__':
    n, m = map(int, input().split())
    a = [list(input()) for i in range(n)]
    b = [list(input()) for i in range(m)]
    main()
