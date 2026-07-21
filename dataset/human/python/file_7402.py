def resolve():
    S = input()
    Q = int(input())
    reverse = False
    import collections
    left = collections.deque([])
    right = collections.deque([])
    for i in range(Q):
        query = input().split()
        if query[0] == "1":
            reverse = (not reverse)
            continue
        if query[1] == "1":
            if reverse:
                right.append(query[2])
            else:
                left.appendleft(query[2])
        elif query[1] == "2":
            if reverse:
                left.appendleft(query[2])
            else:
                right.append(query[2])
    if reverse:
        ans = "{}{}{}".format("".join(reversed(right)), "".join(reversed(S)), "".join(reversed(left)))
    else:
        ans = "{}{}{}".format("".join(left), S, "".join(right))
    print(ans)


if '__main__' == __name__:
    resolve()
