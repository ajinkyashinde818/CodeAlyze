def main():
    from collections import deque
    S = input()
    Q = int(input())
    rev = 0  # 1のとき反転
    que = deque((s for s in S))
    for _ in range(Q):
        Cmd = [i for i in input().split()]
        if Cmd[0] == "1":
            rev ^= 1
        else:
            if rev == 0:
                if Cmd[1] == "1":
                    # 先頭に追加
                    que.appendleft(Cmd[2])
                else:
                    # 末尾に追加
                    que.append(Cmd[2])
            else:
                if Cmd[1] == "1":
                    # 先頭に追加
                    que.append(Cmd[2])
                else:
                    # 末尾に追加
                    que.appendleft(Cmd[2])
    ans = "".join(que)
    if rev == 1:
        ans = ans[::-1]
    print(ans)


if __name__ == '__main__':
    main()
