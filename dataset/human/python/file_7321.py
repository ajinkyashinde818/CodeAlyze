def main():
    s = input()
    q = int(input())

    reverse = 0
    head = ""
    tail = ""

    for i in range(q):
        v = list(input().split())
        if int(v[0]) == 1:
            reverse += 1
        elif reverse % 2 == 0:
            if int(v[1]) == 1:
                head += v[2]
            else:
                tail += v[2]
        elif reverse % 2 == 1:
            if int(v[1]) == 1:
                tail += v[2]
            else:
                head += v[2]

    s = head[::-1] + s + tail
    if reverse % 2 == 1:
        s = s[::-1]

    print(s)


if __name__ == "__main__":
    main()
