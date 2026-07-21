def resolve():
    d,g = map(int,input().split())
    pc = [list(map(int, input().split())) for _ in range(d)]
    ans = 10**9
    for i in range(2**d):
        count = 0
        total = 0
        nokori = [1 for _ in range(d)]
        for j in range(d):
            if (i>>j & 1):
                total += pc[j][0] * (j+1)* 100 + pc[j][1]
                count += pc[j][0]
                nokori[j] = 0
        if total >= g:
            ans = min(ans, count)
        else:
            for k in reversed(range(len(nokori))):
                if nokori[k] == 0:
                    continue
                else:
                    if total + (pc[k][0]-1) * (k+1) *100 >= g:
                        count += (((g-total) + (k+1)*100)-1)//((k+1)*100)
                        ans = min(ans, count)
                        break
                    else:
                        total += (pc[k][0]-1) * (k+1) *100
                        count += (pc[k][1]-1)
    print(ans)
resolve()
