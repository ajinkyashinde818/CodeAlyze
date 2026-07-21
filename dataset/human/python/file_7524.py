def resolve():
    S = input()
    Q = int(input())

    rev = 0
    append_front_rev = ''
    append_rear = ''

    for i in range(Q):
        T = input().split()

        if (T[0] == "1"):
            rev ^= 1
            continue

        if (T[0] == "2" and T[1] == "1"):
            if rev == 0:
                append_front_rev += T[2]
            else:
                append_rear += T[2]
            continue

        if (T[0] == "2" and T[1] == "2"):
            if rev == 0:
                append_rear += T[2]
            else:
                append_front_rev += T[2]
            continue

    ans = append_front_rev[::-1] + S + append_rear
    if rev:
        ans = ans[::-1]

    print("".join(ans))


resolve()
