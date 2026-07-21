def q3():
    import itertools
    l1 = input().split()
    D = int(l1[0])  # 問題数
    G = int(l1[1])  # 総合スコア

    P = []  # 各スコアごとの問題数
    C = []  # コンプリートボーナス
    for i in range(D):
        l = input().split()
        P.append(int(l[0]))
        C.append(int(l[1]))

    # コンプリートするかしないかの組み合わせ作成 2^D個, する:1 しない:0
    for i in range(D):
        li = list(itertools.product([1, 0], repeat=D))

    ans = float('INF')
    for e in li:
        tmp_sum = 0  # 総得点
        tmp_ans = 0  # 総正解数

        # コンプリートした問題だけを先に足しておく
        for i, flag in enumerate(e):
            tmp_sum += (P[i]*(i+1)*100 + C[i]) * flag
            tmp_ans += P[i]*flag

        # print(tmp_sum, tmp_ans, e)

        # コンプリートボーナスだけで目標点数Gを超えているか？
        if tmp_sum >= G:
            ans = min(ans, tmp_ans)  # ans更新
            continue

        for i in range(D-1, -1, -1):
            if e[i] == 1:
                continue
            for _ in range(0, P[i]):
                tmp_sum += (i+1)*100
                tmp_ans += 1
                # print(i, tmp_sum)

                if tmp_sum >= G:
                    ans = min(ans, tmp_ans)  # ans更新
                    break
            if tmp_sum >= G:
                break

    return ans

if __name__ == "__main__":
    print(q3())
