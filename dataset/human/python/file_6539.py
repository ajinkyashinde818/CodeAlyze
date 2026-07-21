if __name__ == '__main__':
    s = input()
    q = int(input())

    pref = []
    suff = []
    rev = False

    for i in range(q):
        curr = [c for c in input().split()]
        if curr[0] == '1':
            rev = not rev
        else:
            if curr[1] == '1':
                if not rev:
                    pref.append(curr[2])
                else:
                    suff.append(curr[2])
            else:
                if not rev:
                    suff.append(curr[2])
                else:
                    pref.append(curr[2])

    res = "{}{}{}".format("".join(pref[::-1]), s, "".join(suff))
    if rev:
        print(res[::-1])
    else:
        print(res)
