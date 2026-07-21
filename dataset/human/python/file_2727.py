import sys
sys.setrecursionlimit(10 ** 5 + 10)


def input(): return sys.stdin.readline().strip()


def resolve():

    D, G = map(int, input().split())
    P, C = [0] * D, [0] * D
    for i in range(D):
        P[i], C[i] = map(int, input().split())
    ans = 10**10

    # 昇順での探索だよ
    for i in range(2 ** D):
        checked = [False]*D
        pnt = 0
        cnt = 0

        for j in range(D):  # このループが一番のポイント
            if ((i >> j) & 1):  # 順に右にシフトさせ最下位bitのチェックを行う
                pnt += C[j]
                pnt += P[j]*(j+1)*100
                checked[j] = True
                cnt += P[j]
        if pnt < G:
            for k in reversed(range(D)):
                if not checked[k]:
                    prob_cnt = 0
                    br_fl = False

                    while prob_cnt < P[k]-1:
                        pnt += (k+1)*100
                        cnt += 1
                        prob_cnt += 1
                        if pnt >= G:
                            br_fl = True
                            break
                    if br_fl:
                        break
        if pnt >= G:
            ans = min(ans, cnt)

    print(ans)


resolve()
