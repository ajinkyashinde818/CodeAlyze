def solve(s):
    r = s[::-1]
    l = len(s)
    sn, rn = 0, 0
    ins = 0

    while True:
        if sn + rn > l:
            return ins
        sc = s[sn]
        rc = r[rn]
        if sc == rc:
            sn += 1
            rn += 1
            continue
        if sc == 'x':
            sn += 1
            ins += 1
            continue
        if rc == 'x':
            rn += 1
            ins += 1
            continue
        return -1


print(solve(input()))
