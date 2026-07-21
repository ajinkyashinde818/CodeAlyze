import math
D, G = map(int, input().split())

P = []
for _ in range(D):
    p, c = map(int, input().split())
    P.append((p, c))

ans = 10000
for i in range(2 ** D):
    score = 0
    solve = 0
    maxj = -1
    for j in range(D):  # このループが一番のポイント
        if ((i >> j) & 1):  # 順に右にシフトさせ最下位bitのチェックを行う
            score += (j+1)*P[j][0]*100+P[j][1]
            solve += P[j][0]
        else:
            maxj = max(maxj, j)

    if maxj == -1:
        if score >= G:
            ans = min(ans, solve)
    elif score+(maxj+1)*(P[maxj][0]-1)*100 >= G:
        solve += max(0, math.ceil((G-score)/(maxj+1)/100))
        ans = min(ans, solve)
    # print(bin(i), ans, solve, score, maxj, score+(maxj+1)*(P[maxj][0]-1))

print(ans)
