import math


D,G = map(int, input().split())
PC = [tuple(map(int, input().split())) for _ in range(D)]


"""
Dがちいさいのでビット全探索させたそう
中途半端に色んな得点の問題を解くより、全部解く問題と部分的に解く問題に分かれるはず。
で、部分的に解く問題は、残りの中で一番得点が高い物を選ぶのがよい。
で、それを必要な分（あるいは全部-1）解いて得られる点がGを超えていれば、答えの候補になる
候補の中から最小のを選んで終わり
"""

ans = []
for bit in range(1 << D):
    point = 0
    cnt = 0
    for i in range(D):
        if bit & (1 << i):
            point += 100*(1+i)*PC[i][0] + PC[i][1]
            cnt += PC[i][0] 

    idx = -1
    for i in range(D):
        if not bit & (1 << i):
            idx = i

    if idx == -1:
        ans.append(cnt)
    else:
        rem = max(0, G - point)
        if rem == 0:
            ans.append(cnt)
        else:
            extr_cnt = math.ceil(rem / (100*(idx+1)))
            if extr_cnt <= PC[idx][0]-1:
                ans.append(cnt+extr_cnt)


print(min(ans))
