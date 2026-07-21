'''

1 <= D <= 10
1 ≤  pi≤100
100≤ ci≤10**6
100≤ G

＜回答・解説より＞
以下のような選択のみを考慮しても最適解はそれらの選択に含まれます。
• 中途半端に解く配点は 1 種類以下であり、それ以外の配点は完全に解くかまったく解かない。
• 中途半端に解く配点があるなら、それは完全に解く配点以外の配点の中で最も高い配点である。

このような選択をすべて列挙するには、D 種類の配点それぞれに対してその配点を完全に解くか否かを決定し、
必要であれば残りの配点のうち最も高いものを中途半端に解く配点とすればよいです
（中途半端に解く配点の問題を 1 問除きすべて解いても目標点に達しない場合は、完全に解く配点の選択が不適切であったとして無視します）。

↓
考え方
「ある点数帯の問題を全部解く」を全パターン試す。
・目標点数を満たす、最小の問題数（の組み合わせ）をAとする
・Aの次に目標点数に近い（が満たさない、組み合わせ）をBとする。
　→Bに、「完全に解く配点以外の配点の中で最も高い配点」の問題を条件を満たすまで解いて問題数を確認する。B'とする
　　→AとB'のうち、解く問題数が少ないほうを回答とする。

'''
# from collections import deque # キュー、スタックに利用
# import math # 数学的計算に利用
# import numpy as np # 行列計算などに利用

# sys.stdin.readline() # 標準入力の高速化に利用
import sys
input = sys.stdin.readline

inf = float('inf')
is_debug = False

d,g = map(int, input().split())

M = [list(map(int, input().split())) for _ in range(d)]

def main():
    '''メイン処理'''
    # 各点数帯の問題を全て解くor全て解かない　の組み合わせパターンは、2**d通り
    points_list = []
    for i in range(2**d):
        # 全て解くフラグのリスト
        solve_list = [0] * d
        # n桁の2進数文字列を生成
        bin_str = bin(i)[2:].zfill(d)
        # 2進数で1の立っている桁をフラグとみなし、全て解くフラグを1へ書き換え
        for j in range(d):
            if bin_str[j] == '1':
                solve_list[j] = 1

        solve_num = 0
        points = 0
        for k in range(d):
            if solve_list[k] == 1:
                q_num, bonus = M[k]
                solve_num += q_num
                points += (q_num*(k+1)*100) + bonus
        points_list.append([solve_num, points, solve_list])
    
    if is_debug:
        print(sorted(points_list))
    
    min_solve_num = inf
    for index, [solve_num, points, solve_list] in enumerate(sorted(points_list, reverse=True)):
        next_loop = False
        if points >= g and solve_num < min_solve_num:
            # 目標点数を満たす、最小の問題数（の組み合わせ）をAとする
            a_ans = [solve_num, points]
            min_solve_num = solve_num
        elif points < g and solve_num < min_solve_num:
            ## Aの次に目標点数に近い（が満たさない、組み合わせ）をBとし、追加で解いて目標点数を満たせばmin_solve_numを更新
            # 解いていない問題の中で、得点が高い順に解いて、目標点を超えた時点のsolve_numをここまでのmin_solve_numと比較する
            for i in range(len(solve_list)-1,-1,-1):
                if solve_list[i] == 0:
                    q_num = M[i][0]
                    for _ in range(q_num):
                        points += (i+1)*100
                        solve_num += 1
                        if solve_num >= min_solve_num:
                            next_loop = True
                        elif points >= g and solve_num < min_solve_num:
                            min_solve_num = solve_num # 条件を満たす問題数があったら、ここまでの最小値を更新
                        
                        if next_loop:
                            break
                if next_loop:
                    break

    if is_debug:
        print(a_ans)
    print(min_solve_num)


if __name__ == "__main__":
    # ファイル実行時に、main()関数を実行
    main()
