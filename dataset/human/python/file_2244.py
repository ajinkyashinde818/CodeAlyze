import sys
import math

def resolve():
    D, G = list(map(int, input().split(" ")))
    P = []
    C = []
    for i in range(D):
        p, c = list(map(int, input().split(" ")))
        P.append(p)
        C.append(c)

    mincnt = float("Inf")
    for bits in range(1<<D):
        score = 0
        cnt = 0
        # bitが立っている桁は全問題解く
        for odr in range(D):
            if (bits & (1<<odr)):
                score += (P[odr] * 100 * (odr+1) + C[odr])
                cnt += P[odr]
        if score >= G:
            mincnt = min(mincnt, cnt)
        else:
            for odr in range(D-1, -1, -1):
                if (bits & (1<<odr)):
                    continue
                for j in range(P[odr]):
                    if score >= G:
                        break
                    score += (odr+1) * 100
                    cnt += 1
            mincnt = min(mincnt, cnt)
    print(mincnt)

if '__main__' == __name__:
    resolve()
