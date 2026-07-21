n = 0
m = 0
aa = []
bb = []


def match(y0, x0):
    global m, aa, bb
    for i, y in enumerate(range(y0, y0 + m)):
        if aa[y][x0:(x0 + m)] != bb[i]:
            return False
    return True


def main():
    global n, m, aa, bb
    n, m = map(int, input().split())
    aa = [input() for _ in range(n)]
    bb = [input() for _ in range(m)]
    for y0 in range(n - m + 1):
        for x0 in range(n - m + 1):
            if match(y0, x0):
                print('Yes')
                return
    print('No')


if __name__ == '__main__':
    main()
