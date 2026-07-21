def read_input():
    n = int(input())
    alist = list(map(int, input().split()))

    return n, alist


def submit():
    n, alist = read_input()

    total = sum(alist)

    s = 0
    mindiff = float('inf')
    for i in range(n - 1):
        s += alist[i]
        rest = total - s

        diff = abs(s - rest)
        if diff < mindiff:
            mindiff = diff

    print(mindiff)

if __name__ == '__main__':
    submit()
