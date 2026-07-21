import sys
def input(): return sys.stdin.readline().strip()


def main():
    D, G = map(int, input().split())
    question = []
    bonus = []
    for i in range(D):
        p, c = map(int, input().split())
        question.append(p)
        bonus.append(c)

    """
    決め打ち二分探索と思い込んで「x問解いて得られる最大得点」を出そうとして撃沈。。。
    結局その発想をしたところで、肝は
        ・どのボーナスを得るか
        ・ボーナスを取らない「唯一の」得点群はどれか
    なので、それなら初めからこれに着目して問題を解いたうえで、それが得点Gを超えるかどうか
    確かめた方が早い。
    """ 

    ans = sum(question)
    for state in range(1 << D):
        # ビットが立ってたら全完
        score = 0
        num = 0
        solved = set([])
        for i in range(D):
            if state & (1 << i):
                solved.add(i)
                num += question[i]
                score += 100 * (i + 1) * question[i] + bonus[i]
        if score >= G:
            ans = min(ans, num)
            continue

        # G点未満の場合は解いてない問題のうち最高得点のものを追加で解く
        last_idx = D - 1
        while last_idx in solved: last_idx -= 1
        for i in range(question[last_idx]):
            score += 100 * (last_idx + 1)
            num += 1
            if score >= G:
                ans = min(ans, num)
                break
    print(ans)


if __name__ == "__main__":
    main()
