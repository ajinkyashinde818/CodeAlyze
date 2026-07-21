def string():
    s = input()
    q = int(input())
    l = ''
    r = ''
    re = False
    for _ in range(q):
        t = input().split()
        if t[0] == '1':
            re = not re
        else:
            if re:
                if t[1] == '1':
                    r = r + t[2]
                else:
                    l = t[2] + l
            else:
                if t[1] == '1':
                    l = t[2] + l
                else:
                    r = r + t[2]
    s = l + s + r
    if re:
        s = s[::-1]
    print(s)
string()
