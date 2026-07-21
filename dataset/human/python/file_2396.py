def IL(): return list(map(int, input().split()))
d, g = IL()
p = [0] * d
c = [0] * d
cpl = [False] * d
ans = 10000
for i in range(d):
    p[i], c[i] = IL()
for i in range(2 ** d):
    cnt = 0
    score = 0
    cpl = [False] * d
    for j in range(d):
        if i >> j & 1:
            cpl[j] = True
    for j in range(d): #コンプ
        if cpl[j]:
            cnt += p[j]
            score += 100 * (j + 1) * p[j] + c[j]
    if score >= g:
        if cnt < ans:
            ans = cnt
        continue
    for j in reversed(range(d)): #非コンプ
        if not cpl[j]:
            for k in range(p[j] - 1):
                cnt += 1
                score += 100 * (j + 1)
                if score >= g:
                    if cnt < ans:
                        ans = cnt
                    break
            else:
                continue
            break
print(ans)
