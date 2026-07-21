from collections import deque
def main():
    s = deque(input())
    q = int(input())
    qs = [tuple(input().split()) for _ in range(q)]
    flag = 1
    for qse in qs:
        if qse[0] == '1':
            flag ^= 1
        else:
            f = int(qse[1]) - 1
            f ^= flag
            if f:
                s.appendleft(qse[2])
            else:
                s.append(qse[2])
    if flag:
        print("".join(s))
    else:
        ss = list(s)
        print("".join(ss[::-1]))

if __name__ == '__main__':
    main()
