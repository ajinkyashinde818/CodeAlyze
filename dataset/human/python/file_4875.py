url = "https://atcoder.jp/contests/abc082/tasks/abc082_b"


def main():
    s1, s2 = [input() for i in range(2)]
    l1 = sorted(list(s1))
    l2 = sorted(list(s2), reverse=True)
    indx = 0
    if len(l1) > len(l2):
        indx = len(l2)
    else:
        indx = len(l1)
    for i in range(indx):
        if l1[i] < l2[i]:
            print('Yes')
            exit()
    if len(l1) < len(l2) and l1[-1] <= l2[-1]:
        print('Yes')
        exit()
    print('No')




if __name__ == '__main__':
    main()
