import sys


q_size, g_score = map(int, input().split())
q_nums = [0] * q_size
bonus = [0] * q_size
for i in range(0, q_size):
    q_nums[i], bonus[i] = map(int, input().split())


def solve_q(score, q_cnt, q_solved, best_cnt):
    # ボーナスだけでGを突破していたら、そのまま返却する
    if score >= g_score: 
        return min(best_cnt, q_cnt)
    
    # 現状でどの問題が何問残っているかキャッシュし、配点の高い問題から先に解いていく
    q_remained = [0] * q_size
    for i in range(0, q_size):
        q_remained[i] = q_nums[i] - q_solved[i]
        
    for i in range(q_size - 1, -1, -1):
        while q_remained[i] > 0: # Gに達成するまで、あるだけ全部解く
#            print("while in score: ", score)
            score += 100 * (i + 1)
            q_cnt += 1
            q_remained[i] -= 1
            
            if score >= g_score:
                return min(best_cnt, q_cnt)
            
    # ボーナス未反映で、解なしの場合
    return min(best_cnt, q_cnt)

            
best_cnt = sum(q_nums)
# 各Qのボーナスを 使う or 使わない で分岐
for bi in range(0, 2 ** q_size):
    # 初期化
    score = 0
    q_cnt = 0
    q_solved = [0]*q_size

    for pos_i in range(0, q_size):
        if (bi >> pos_i) & 1: # True: ボーナスを使う
            score += 100 * (pos_i + 1) * q_nums[pos_i] + bonus[pos_i]
            q_cnt += q_nums[pos_i]
            q_solved[pos_i] += q_nums[pos_i]
            
    # スコアを引き継いで、得点の高い問題から解いていく
#    print(score, q_cnt, q_solved, best_cnt)
    best_cnt = solve_q(score, q_cnt, q_solved, best_cnt)
    

print(best_cnt)
