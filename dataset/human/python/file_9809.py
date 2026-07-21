def main():
    import sys
    n, k, *a = map(int, sys.stdin.read().split())
    a = [0] + a
    check = [0] * (n + 1)
    check[1] = 1

    i = 0
    nw = 1
    path = [1]
    while True:
        nx = a[nw]
        i += 1
        if i == k:
            print(nx)
            break
        if check[nx]:
            j = path.index(nx)
            d = j + (k - i) % (i - j)
            print(path[d])
            break
        path.append(nx)
        check[nx] = True
        nw = nx


if __name__ == '__main__':
    main()
