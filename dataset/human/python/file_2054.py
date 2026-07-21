def main():
    N = int(input())
    S = input()

    str_list = list()
    for s in S:
        str_list.append(s)

    str_uni_list = {}
    for str in str_list:
        if (str in str_uni_list) is False:
            str_uni_list[str] = 1
        else:
            str_uni_list[str] += 1

    list_val = []
    for i in str_uni_list.values():
        list_val.append(i)

    rem = 1
    for v in list_val:
        rem *= (v + 1)

    ans = rem - 1

    print(ans % (10 ** 9 + 7))


if __name__ == '__main__':
    main()
