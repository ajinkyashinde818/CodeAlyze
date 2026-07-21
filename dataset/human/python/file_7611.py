def resolve():
    S = str(input())
    Q = int(input())

    rev_flag = 1
    head_str = ""
    tail_str = ""
    for _ in range(Q):
        query = input() # contains spaces
        if query[0] == "1":
            rev_flag *= -1
        else:
            h_or_t_flag = 1 if query[2] == "1" else -1
            h_or_t_flag *= rev_flag

            if h_or_t_flag == 1:
                head_str += query[4]
            else:
                tail_str += query[4]

    ans = head_str[::-1] + S + tail_str
    print(ans if rev_flag == 1 else ans[::-1])
resolve()
