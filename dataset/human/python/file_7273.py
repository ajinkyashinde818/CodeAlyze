def main():
    s = input()
    q = int(input())

    rule = 0
    pre, suf = '', ''
    for _ in range(q):
        query = input()
        if query[0] == '1':
            rule += 1
        else:
            if rule % 2 == 0:
                if query[2] == '1':
                    pre = query[4] + pre
                else:
                    suf += query[4]
            else:
                if query[2] == '1':
                    suf += query[4]
                else:
                    pre = query[4] + pre

    s = pre + s + suf
    print(s if rule % 2 == 0 else s[::-1])


if __name__ == '__main__':
    main()
