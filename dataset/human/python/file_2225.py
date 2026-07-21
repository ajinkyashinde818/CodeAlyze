N, G = map(int, input().split())
bonus = []
problems = []
for _ in range(N):
    PI, CI = map(int, input().split())
    problems.append(PI)
    bonus.append(CI)


def calc_rest_score():
    total = 0
    for i, pi in enumerate(problems):
        if pi:
            score = (i+1) * 100
            total += score * pi + bonus[i]
    return total


def make_plan(total_problem, total_score, flag):
    """
    :param total_score: ここまでの合計スコア
    :param total_problem: ここまでの合計問題数
    :param flag: 最後のスコア調整実施済みフラグ
    :return: 合計問題数
    """
    if total_score >= G:
        return total_problem

    # print("call ", total_problem, total_score, problems)

    rest_score = calc_rest_score()  # 残り全部解いたら何点になるのか
    if total_score + rest_score < G:
        # もう無理
        return 10000

    for i in range(N - 1, -1, -1):
        pi = problems[i]
        si = (i + 1) * 100
        if pi == 0:
            continue
        else:
            # 1. 全部解く
            problems[i] = 0
            pn1 = make_plan(total_problem + pi,
                            total_score + si * pi + bonus[i],
                            flag)
            problems[i] = pi
            # print("pn1:", pn1)

            # 2. 部分的に解く(ただし最後の調整として)
            if not flag:
                # 1問ずつ減らして結果を比較
                min_pn = 10000  # 多分問題数はmaxでも5500問くらい
                for j in range(pi, -1, -1):  # 1～(pi-1)
                    plus_score = si * j
                    if j == pi:
                        plus_score += bonus[i]
                    problems[i] = 0
                    pn = make_plan(total_problem+j,
                                   total_score+plus_score,
                                   True if j != 0 else flag)
                    # print("test", j, pn)
                    problems[i] = pi
                    if pn < min_pn:
                        min_pn = pn
                pn2 = min_pn
            else:
                pn2 = 10000

            return min(pn1, pn2)
    else:
        # 問題を避けすぎて解けない
        return 10000


print(make_plan(0, 0, False))
