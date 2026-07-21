def hantei(s, h):
    try:
        slen = len(s)
        hlen = len(h)
        res = s.index(h, slen - hlen, slen + 1)
        return res
    except ValueError as e:
        return -1


def resolve():
    s = input()
    a = 'dream'
    b = 'dreamer'
    c = 'erase'
    d = 'eraser'
    while True:
        # 後ろから文字列検索
        # 合ったらその文字を削除
        D = hantei(s, d)
        if D > -1:
            s = s[:-len(d)]
            continue
        B = hantei(s, b)
        if B > -1:
            s = s[:-len(b)]
            continue
        C = hantei(s, c)
        if C > -1:
            s = s[:-len(c)]
            continue
        A = hantei(s, a)
        if A > -1:
            s = s[:-len(a)]
            continue
        if len(s) == 0:
            print('YES')
        else:
            print('NO')
        break
        
resolve()
