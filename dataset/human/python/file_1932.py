def read_input():
    n, m = map(int, input().split())

    alist = []
    for i in range(n):
        alist.append(input().strip())

    blist = []
    for i in range(m):
        blist.append(input().strip())

    return n, m, alist, blist




def submit():
    n, m, alist, blist = read_input()

    for i in range(n - m + 1):
        for j in range(n - m + 1):

            check = True
            for x in range(m):
                for y in range(m):
                    if alist[i + x][j + y] != blist[x][y]:
                        check = False
                        break
                if not check:
                    break

            if check:
                print('Yes')
                return

    print('No')


if __name__ == '__main__':
    submit()
