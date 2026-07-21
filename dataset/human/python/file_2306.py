import itertools
D, G = map(int, input().split())
pc = [list(map(int, input().split())) for _ in range(D)]
bit = itertools.product([0, 1], repeat=D)
ans = 1000
for bi in bit:
    cnt = 0
    score = 0
    nokori = []
    for i in range(D):
        if bi[i] == 0:
            nokori.append([pc[i][0], (i+1)*100])
            continue
        score += pc[i][1] + 100*(i+1)*(pc[i][0])
        cnt += pc[i][0]
    if score >= G:
        ans = min(ans, cnt)
    else:
        for num, point in reversed(nokori):
            for j in range(1, num):
                cnt += 1
                score += point
                if score >= G:
                    ans = min(ans, cnt)
                    break
            else:
                continue
            break
print(ans)
