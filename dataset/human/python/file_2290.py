from itertools import product
from math import ceil
def main():
    d, g = map(int, input().split())
    scoremax_set = []
    numq_set = []
    for i1 in range(1, d + 1):
        kazu, bonus = map(int, input().split())
        scoremax_set.append(i1 * 100 * kazu + bonus)
        numq_set.append(kazu)
    score_get_pat = tuple(product((1,0), repeat=d))

    inf = float('inf')
    r = inf

    for sgpe in score_get_pat:
        score = 0
        q_num = 0
        for j1, s in zip(sgpe, scoremax_set):
            score += j1 * s
        for j2, num in zip(sgpe, numq_set):
            q_num += j2 * num
        if score >= g:
            r = min(r, q_num)
        else:
            sgpe_l = [i for i, x in enumerate(sgpe) if x == 0]
            score_plus = (sgpe_l[-1]+1)*100 * (numq_set[sgpe_l[-1]] - 1)
            if score + score_plus >= g:
                q_num += ceil((g - score) / ((sgpe_l[-1]+1)*100))
                r = min(r, q_num)
    print(r)


if __name__ == '__main__':
    main()
