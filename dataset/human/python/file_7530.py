from collections import deque

def main():
    S = deque(input())
    Q = int(input())
    revFlag = False
    for i in range(Q):
        tmp = list(input().split())
        if tmp[0] == "1":
            if revFlag:
                revFlag = False
            else:
                revFlag = True
        else:
            if tmp[1] == "1":
                if revFlag:
                    S.append(tmp[2])
                else:
                    S.appendleft(tmp[2])
            else:
                if revFlag:
                    S.appendleft(tmp[2])
                else:
                    S.append(tmp[2])
    if revFlag:
        S.reverse()
    print("".join(S))


if __name__ == '__main__':
    main()
