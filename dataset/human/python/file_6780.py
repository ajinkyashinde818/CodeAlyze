from collections import deque


def main():
    S = input()
    Q = int(input())

    d = deque(S)

    r = False
    for _ in range(Q):
        q = input()
        if q == '1':
            r = not r
        else:
            _, b, c = q.split()
            if r:
                if b == '1':
                    d.append(c)
                else:
                    d.appendleft(c)
            else:
                if b == '1':
                    d.appendleft(c)
                else:
                    d.append(c)

    if r:
        d.reverse()
    print("".join(d))


if __name__ == "__main__":
    main()
