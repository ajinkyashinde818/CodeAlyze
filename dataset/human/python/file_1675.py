def main():
    n, m = map(int, input().split())
    a = [input() for i in range(n)]
    b = [input() for i in range(m)]

    for row in range(n - m + 1):
        for index in range(n - m + 1):
            if b == [i[index:index + m] for i in a[row:row + m]]:
                print('Yes')
                return

    print('No')

    # for row in range(n - m + 1):
    #    current_index = 0
    #    for index in range(n - m + 1):
    #        current_index = a[row].find(b[0], index)
    #        if current_index < 0:
    #            break
    #
    #        for i in range(m):
    #            if a[row + i].find(b[i], current_index) != current_index:
    #                break
    #        else:
    #            print('Yes')
    #            return
    #
    # print('No')


if __name__ == "__main__":

    main()
