def main():
    from collections import deque
    S = input()
    Sd = deque(list(S))
    Q = int(input())
    Query = [input().split() for i in range(Q)]
    flag = 0
    for q in Query:
        if q[0] == "1":
            flag += 1
        elif q[0] == "2":
            if q[1] == "1":
                if flag % 2 == 1:
                    Sd.append(q[2])
                elif flag % 2 == 0:
                    Sd.appendleft(q[2])
            elif q[1] == "2":
                if flag % 2 == 1:
                    Sd.appendleft(q[2])
                elif flag % 2 == 0:
                    Sd.append(q[2])

    if flag % 2 == 1:
        Sd.reverse()
        print("".join(Sd))
    elif flag % 2 == 0:
        print("".join(Sd))

if __name__ == "__main__":
    main()
