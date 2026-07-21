from itertools import product

d, g = map(int, input().split())
q = [list(map(int, input().split())) for _ in range(d)]

bits = product((0, 1), repeat=d)

least_cnt = float('inf')

for bit in bits:
    sum_of_points = 0
    cnt = 0
    cnt_increment = 0
    
    for i in range(d):
        if bit[i]:
            sum_of_points += 100*(i+1)*q[i][0] + q[i][1]
            cnt += q[i][0]
    
    if sum_of_points < g:
        for i in reversed(range(d)):    # 大きい方から探す
            if not bit[i]:
                if sum_of_points + 100*(i+1)*q[i][0] < g:   # ほぼ全問解いても点数が足りない
                    continue
                while sum_of_points < g:
                    sum_of_points += 100*(i+1)
                    cnt += 1
                break
    if sum_of_points >= g:
        least_cnt = min(least_cnt, cnt)

print(least_cnt)
