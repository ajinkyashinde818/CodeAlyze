import sys
from pprint import pprint

import math

d, g = map(int, sys.stdin.readline().strip().split(" "))

p = []
c = []
for _ in range(d):
    p_i, c_i = map(int, sys.stdin.readline().strip().split(" "))
    p.append(p_i)
    c.append(c_i)

ans = 10 ** 9
for i in range(2**d):
    use = [0] * d
    for j in range(d):
        if ((i >> j) & 1):
            use[d - 1 - j] = 1
    # pprint(use)
    score = 0
    tmp_ans = 0
    max_i = -1
    for i, use_i in enumerate(use):
        if use_i:
            tmp_ans += p[i]
            score += p[i] * (i+1) * 100 + c[i]
        else:
            max_i = i
    # print("tmp_ans: ", tmp_ans, " score:", score, " max_i:", max_i)
    if score < g  and max_i > -1:
        num = math.ceil((g - score) / ((max_i+1) * 100))
        # print("num:", num)
        if num < p[max_i]:
            tmp_ans += num
            score += num * ((max_i+1) * 100)
    # print(tmp_ans, score)
    if score >= g:
        ans = min(ans, tmp_ans)
        
print(ans)
