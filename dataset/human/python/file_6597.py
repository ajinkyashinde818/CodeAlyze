def main():
    s = list(input())
    t = []
    q = int(input())

    for _ in range(q):
        query = list(input().split())

        if query[0] == "1":
            s, t = t, s
        elif query[0] == "2":
            if query[1] == "1":
                t.append(query[2])
            elif query[1] == "2":
                s.append(query[2])

    print(*(t[::-1] + s), sep="")


if __name__ == "__main__":
    main()
