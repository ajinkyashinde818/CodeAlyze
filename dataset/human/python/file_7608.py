from collections import deque


def main():
    S = deque(list(input()))
    Q = int(input())
    count = 0
    for _ in range(Q):
        query = list(input().split())
        if query[0] == "1":
            count += 1
        if query[0] == "2":
            if count % 2 == 0:
                if query[1] == "1":
                    S.appendleft(query[2])
                elif query[1] == "2":
                    S.append(query[2])
            else:
                if query[1] == "1":
                    S.append(query[2])
                elif query[1] == "2":
                    S.appendleft(query[2])
    if count % 2 == 0:
        ans = "".join(S)
        print(ans)
    else:
        S.reverse()
        ans = "".join(S)
        print(ans)


if __name__ == '__main__':
    main()
