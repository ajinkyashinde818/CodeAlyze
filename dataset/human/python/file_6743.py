from collections import deque


def main():
    s = deque(list(input()))
    q = int(input())
    rev = False
    for _ in range(q):
        query = input().split()
        if query[0] == "1":
            if not rev:
                rev = True
            else:
                rev = False
        else:
            if query[1] == '1':
                pass
                if rev:
                    s.append(query[2])
                else:
                    s.appendleft(query[2])
            else:
                if rev:
                    s.appendleft(query[2])
                else:
                    s.append(query[2])
    if rev:
        s.reverse()
    print(*s, sep="")


if __name__ == "__main__":
    main()
