def main():
    D, G = [int(i) for i in input().split()]
    p = []
    c = []
    for i in range(D):
        pp, cc = [int(i) for i in input().split()]
        p.append(pp); c.append(cc)
    ans = 1e9
    for mask in range(1<<D):
        s = 0; num = 0; rest_max = -1
        for i in range(D):
            # どのビットが立っているか確認する
            if mask >> i & 1:
                # i 番目の問題を全完した時の点数を追加する
                s += 100 * (i+1) * p[i] + c[i]
                num += p[i]
            else:
                # ビットが立っていない点数が一番高い問題のメモ
                # 足りなかったらここから解いて点数を追加する
                # 残ったやつ 1 つだけを見ればばいい
                # なぜなら、bit全探索で、他のパターンは自動的に出るから
                rest_max = i
        if s < G:
            # rest_max 番目の点数をあらかじめ計算しておく
            s1 = 100 * (rest_max+1)
            # 目標 - 今まで解いた問題の得点 + rest_max 番目の問題の得点 - 1
            need = (G - s + s1 - 1) // s1 # max になってはいけない
            if need >= p[rest_max]:
                continue
            num += need
        ans = min(ans, num)
    print(ans)


if __name__ == '__main__':
    main()
