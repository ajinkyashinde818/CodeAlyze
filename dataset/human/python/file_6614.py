def solve():
    s1 = input()
    s2 = ''
    q = int(input())
    flg = 0
    for i in range(q):
        a = input().split()
        if a[0] == '1':
            flg = 1 - flg
        else:
            if flg == 0 and a[1] == '2' or flg == 1 and a[1] == '1':
                s1 += a[2]
            else:
                s2 += a[2]
    if flg == 0:
        print(s2[::-1] + s1)
    else:
        print(s1[::-1] + s2)
solve()
