d, g = map(int,input().split())
p=[0]*d
c=[0]*d
for i in range(d):
    p[i], c[i] = map(int,input().split())
import numpy as np
import math
b = 2**d
pnum = np.array(p)
cnum = np.array(c)
ans = 10**30
score_comp = np.zeros(d)
for di in range(d):
    score_comp[di] = pnum[di]*(100*(di+1))+cnum[di]

for i in range(b):
    comp_str = bin(i)[2:].zfill(len(bin(b-1))-2)
    comp_num = np.array([float(j) for j in list(comp_str)])
    comp_cnt = int((comp_num*pnum).sum())
    total_comp_score = (comp_num*score_comp).sum()
    if total_comp_score >= g:
        if ans > comp_cnt:
            ans = comp_cnt
    else:
        rest = g-total_comp_score
        rest_id = comp_str.rfind('0')
        if rest_id>=0:
            rest_cnt = math.ceil(rest/(rest_id+1)/100)
            if pnum[rest_id] > rest_cnt:
                if (ans > comp_cnt + rest_cnt):
                    ans = comp_cnt + rest_cnt
print(ans)
