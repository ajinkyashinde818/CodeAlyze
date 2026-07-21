import itertools
import math


D, G = map(int, input().split())
basic = []
bonus = {}
p_c_list = []
for i in range(1, D+1):
    p, c = map(int, input().split())
    p_c_list.append([p, c])


min_count = float("inf")
for ans in itertools.product([0, 1], repeat=D):
    point = 0
    count = 0
    for idx, a in enumerate(ans):
        point += (p_c_list[idx][0]*(100*(idx + 1)) + p_c_list[idx][1])*a
        count += p_c_list[idx][0]*a

    if point < G:
        for idx, a in enumerate(reversed(ans)):
            if a == 0:
                plus_count = math.ceil((G - point) / ((D-idx)*100))
                # print(idx, D-idx, p_c_list[D-idx-1], G - point, plus_count)
                if plus_count >=  p_c_list[D-idx-1][0]:
                    count = float("inf")
                    point = 0
                else:
                    count += plus_count
                    point = G
                break
    # print(G, point, count)
    if point >= G:
        min_count = min(min_count, count)

print(min_count)
