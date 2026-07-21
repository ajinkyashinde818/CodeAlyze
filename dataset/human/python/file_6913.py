def solve():
    S = input()
    q = int(input())
    flg = 0
    li = ["", ""]
    for _ in range(q):
        Q = input().split()
        if Q[0] == "1":
            flg = 1 - flg
        else:
            li[(int(Q[1]) - 1 + flg) % 2] += Q[2]
    if flg:
        S = S[::-1]
    print(li[flg][::-1] + S + li[1 - flg])
solve()
