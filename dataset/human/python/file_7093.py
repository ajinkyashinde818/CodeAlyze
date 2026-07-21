from collections import deque

if __name__ == '__main__':
    s = input()
    q = int(input())
    hanten_flag = 0

    d_mae = deque()
    d_ushiro = deque()

    for i in range(q):
        query = input().split(" ")
        if query[0] == "1":
            hanten_flag = (hanten_flag + 1) % 2
        else:
            if query[1] == "1":
                if hanten_flag == 0:
                    d_mae.appendleft(query[2])
                else:
                    d_ushiro.append(query[2])
            else:
                if hanten_flag == 0:
                    d_ushiro.append(query[2])
                else:
                    d_mae.appendleft(query[2])

    if hanten_flag == 0:
        print("".join(list(d_mae)) + s + "".join(list(d_ushiro)))

    else:
        print("".join(reversed(list(d_ushiro))) + s[::-1] + "".join(reversed(list(d_mae))))
