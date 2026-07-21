def resolve():
    d, g = map(int, input().split())
    lp, lc = [], []
    while True:
        try:
            p, c = map(int, input().split())
            lp.append(p)
            lc.append(c)
        except EOFError:
            break

    num = sum(lp)
    for i in range(2**d):
        cnt = 0
        scr = 0
        lcn = [0]*d
        for j in range(d):
            if (i // 2**j)%2 == 1:
                cnt += lp[j]
                scr += 100*(j+1)*lp[j]+lc[j]
                lcn[j] += 1
        for j in range(d-1, -1, -1):
            if cnt < num and scr >= g:
                num = cnt
                break
            if lcn[j] == 0:
                for k in range(lp[j]):
                    cnt += 1
                    scr += 100*(j+1)
                    if cnt < num and scr >= g:
                        num = cnt
                        break
                break
    print(num)
resolve()
