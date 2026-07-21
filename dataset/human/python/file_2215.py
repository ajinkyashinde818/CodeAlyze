from sys import stdin
f_i = stdin

D, G = map(int, f_i.readline().split())

score_data = []
for i in range(1, D + 1):
    p, c = map(int, f_i.readline().split())
    score = i * 100
    score_data.append((score, p, c))
score_data.sort(reverse=True)

count_rec = []
def dfs(i, score, count, unsolved):
    if score >= G:
        count_rec.append(count)
    elif i == D:
        if unsolved:
            s, p, c = score_data[unsolved[0]]
            remain = G - score
            if s * p >= remain:
                if remain % s == 0:
                    count_rec.append(count + remain // s)
                else:
                    count_rec.append(count + remain // s + 1)
    else:
        s, p, c = score_data[i]
        dfs(i + 1, score + s * p + c, count + p, unsolved)
        dfs(i + 1, score, count, unsolved + [i])

dfs(0, 0, 0, [])
print(min(count_rec))
