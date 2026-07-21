from collections import deque


def main():
    S = list(input())
    D = deque(S)
    Q = int(input())
    T = [tuple(map(str, input().split())) for _ in range(Q)]
    r = False

    for t in T:
        if t[0] == "1" and r == False:
            r = True
        elif t[0] == "1" and r == True:
            r = False
        else:
            if t[1] == "1" and r == False:
                D.appendleft(t[2])
            elif t[1] == "1" and r == True:
                D.append(t[2])
            elif t[1] == "2" and r == False:
                D.append(t[2])
            elif t[1] == "2" and r == True:
                D.appendleft(t[2])

    if r == False:
        print("".join(D))
    else:
        D.reverse()
        print("".join(D))


if __name__ == "__main__":
    main()
