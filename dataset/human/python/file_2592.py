import itertools


D, G = map(int, input().split())

P     = [None] * D
C     = [None] * D
count = [None] * D
score = [None] * D

for i in range(D):
    p, c          = map(int, input().split())
    P[i]          = p
    C[i]          = c
    count[i]      = list(range(p+1))
    score[i]      = [100 * (i+1) * j for j in range(p+1)]
    score[i][-1] += c

answer = sum(P)

for is_complete in itertools.product([True, False], repeat=D):
    score_tmp  = 0
    count_tmp  = 0
    score_tmp += sum([score[i][-1] for i in range(D) if is_complete[i]])
    count_tmp += sum([count[i][-1] for i in range(D) if is_complete[i]])
    if score_tmp < G:
        for i in list(range(D))[::-1]:
            if is_complete[i] == False:
                if (G - score_tmp) % (100 * (i+1)) == 0:
                    count_add  = min((G - score_tmp) // (100 * (i+1)),     P[i] - 1)
                else:
                    count_add  = min((G - score_tmp) // (100 * (i+1)) + 1, P[i] - 1)
                score_add      = 100 * (i+1) * count_add
                count_tmp     += count_add
                score_tmp     += score_add
            if score_tmp >= G:
                break
    if score_tmp >= G:
        answer = min(answer, count_tmp)

print(answer)
