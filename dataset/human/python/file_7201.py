def main():
    import sys
    from collections import deque
    input = sys.stdin.readline

    s_old = list(str(input()))
    q = int(input())
    pl_mi = 1
    pl_mi_2 = 1
    query = [list(input().split()) for i in range(q)]

    s = deque(s_old)
    s.pop()

    for i in range(q):
        if query[i][0] == "1":
            pl_mi = pl_mi * (-1)
            continue
        else:
            if query[i][1] == "1":
                pl_mi_2 = 1
            else:
                pl_mi_2 = -1
            if pl_mi * pl_mi_2 == 1:
                s.appendleft(query[i][2])
            else:
                s.append(query[i][2])
    
    if pl_mi == 1:
        s_new = "".join(list(s))
        print(s_new)
    else:
        s.reverse()
        s_new = "".join(list(s))
        print(s_new)




if __name__ == "__main__":
    main()
