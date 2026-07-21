import numpy as np
d, g = map(int ,input().split())
points = [list(map(int,input().split())) for _ in range(d)]

def min_q(comp_flg, target_score): # comp_flag[i]=True以外の問題iについて、compポイントを無視してtarget_scoreを超えるには最低いくつの問題数が必要かを返す
    score = 0
    q_num = 0
    for i in range(d-1,-1,-1):
        if comp_flg[i]:
            continue
        if target_score>score+points[i][0]*(i+1)*100:
            score += points[i][0]*(i+1)*100
            q_num += points[i][0] 
        else:
            q_num += np.ceil((target_score-score)/(100*(i+1)))
            break
    return q_num


mn = float('inf')
for i in range(1<<d):
    complete_flg = [False]*d
    tmp_q_num = 0
    tmp_point = 0
    for j in range(d):
        if i&(2**j) != 0:
            tmp_point += points[j][0] * 100*(j+1) + points[j][1]
            complete_flg[j] = True
            tmp_q_num += points[j][0]
    if tmp_point < g:
        tmp_q_num += min_q(complete_flg, g-tmp_point)
    if mn>tmp_q_num:
        mn = tmp_q_num

print(int(mn))
