def main():
    from collections import deque
    S = deque(input())
    Q = int(input())

    q_list = [input().split() for _ in range(Q)]

    flag = False
    for q in q_list:
        if len(q) == 1:
            t = q[0]
        else:
            t, f, c = q

        if t == '1':
            flag = not flag
        else:
            if (f == '1') ^ flag:
                S.appendleft(c)
            else:
                S.append(c)
    if flag:
        S.reverse()
    print("".join(S))


if __name__ == '__main__':
    main()
