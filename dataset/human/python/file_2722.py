import math

D, G = [int(x) for x in input().split()]

P = [0] * (D+1)
C = [0] * (D+1)

for i in range(D):
    p, c = [int(x) for x in input().split()]
    P[i] = p
    C[i] = c

INF = 10**10

def score_cnt(i):
    ret_score = 0
    ret_cnt = 0
    for j in range(D):
        if (1 << j) & i:
            ret_score += C[j]
            ret_score += (j + 1) * 100 *P[j]
            ret_cnt += P[j]
    return ret_score, ret_cnt


ret = INF
for i in range(2 ** D):
    score,cnt = score_cnt(i)
    # print("score:{},cnt:{}".format(score, cnt))
    for j in range(D):
        if score >= G:
            ret = min(ret, cnt)
        else:
            if (1 << j) & i:
                continue
            rest = G - score

            if (j+1)*100 * P[j] >= rest:
                add = math.ceil(rest / ((j+1)*100))
                ret = min(ret, cnt + add)



print(ret)
