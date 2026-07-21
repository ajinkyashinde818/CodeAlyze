def main():
    import collections
    S = input()
    q = collections.deque(S)
    Q = int(input())
    isrev = False
    for _ in range(Q):
        query = input()
        if query == "1":
            isrev = isrev ^ True
        else:
            _, f, c = query.split()
            ishead = (f=="1")
            ishead = ishead ^ isrev
            if ishead:
                q.appendleft(c)
            else:
                q.append(c)
    if isrev:
        q = reversed(q)
    print("".join(q))


if __name__ == '__main__':
    main()
