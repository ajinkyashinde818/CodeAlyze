import math
d,g = map(int, input().split())
l = []
ans = 10**5

for i in range(d):
    l.append(list(map(int, input().split())))

for i in range(2 ** d):
    count = 0
    score = 0
    remain = -1
    for j in range(d):
        if (i >> j) & 1: # j: コンプリートしない問題
            count += l[j][0]
            score += l[j][1] + l[j][0] * 100 * (j+1)
        else:
            remain = j
    if score >= g:
        ans = min(ans, count)
    else:# remain: コンプリートしない問題でもっとも点数の高い問題
        s1 = 100 * (remain+1)
        need_n = math.ceil((g - score) / s1)
        if need_n >= l[remain][0]:
            continue
        count += need_n
        ans = min(ans, count)

print(ans)
