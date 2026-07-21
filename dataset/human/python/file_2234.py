import sys
from collections import defaultdict
input = sys.stdin.readline

D, G = [int(x) for x in input().strip().split()]
P = [''] * D
for d in range(D):
    p, c = [int(x) for x in input().strip().split()]
    P[d] = [0] + [(d + 1) * 100 * (i + 1) for i in range(p)]
    P[d][-1] += c

d = defaultdict(int)
def f(P, D, qnum, trial, d, flag=False, score=[]):
    if (qnum, trial, sum(score)) in d:
        return d[(qnum, trial, sum(score))]
    #print('qnum={}, trial={}, score={}'.format(qnum,trial,score))
    if qnum == D:
        if sum(score) >= G:
            #print('  OK : {}'.format(trial))
            return trial
        else:
            #print('  NG')
            return 10 ** 9 + 7
    ret = 10 ** 9 + 7
    if flag:
        N = [0, len(P[qnum])-1]
    else:
        N = range(len(P[qnum]))
    for n in N:
        flag2 = flag
        t = score[:]
        t.append(P[qnum][n])
        if not flag and n != len(P[qnum]) - 1 and n != 0:
            flag2 = True
        ret = min(ret, f(P, D, qnum+1, trial+n, d, flag2, t))
    d[(qnum, trial, sum(score))] = ret
    return ret

print(f(P, D, 0, 0, d))
