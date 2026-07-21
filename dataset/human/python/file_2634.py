import itertools
from pprint import pprint


d,g = map(int,input().split())

plist=[]
clist=[]

bonus_masterlist=[]

for _ in range(d):
    p_temp,c_temp = map(int,input().split())
    plist.append(p_temp)
    clist.append(c_temp)


bonus_masterlist = list(itertools.product(range(2), repeat=d))
#bit全探索をやらなくても、itertoolsを使えば一瞬でできちゃう。(タプルのリスト)
#for i in range(2**d):
#    bonus_templist = [0] * d
#    for j in range(d):
#        if i >> j & 1:
#            bonus_templist[d-1-j] = 1
#    bonus_masterlist.append(bonus_templist)

#point_list = [100,200,300, ... ,d*100]
#max_list: plist = [p[0],p[1],p[2], ... ,p[d]]
#bonuspoint_list: clist = [c[0],c[1],c[2], ... ,c[d]]

count_list = [0] * d

mincount = 100 * 10

"""
def dfs(i):
    global mincount
    if sum([count_list[i] * 100*(i+1) for i in range(d)]) + sum([bonus_list[j] * clist[j] for j in range(d)]) >= g:
        if sum(count_list) < mincount:
            mincount = sum(count_list)
    elif plist[i] == count_list[i]:
        bonus_list[i] = 1
        dfs(i-1)
    elif plist[i] > count_list[i]:
        count_list[i] += 1
        dfs(i)
    return
"""

for bonus_tuple in bonus_masterlist:
    bonus_list = list(bonus_tuple)
    count_list = [x * y for (x, y) in zip(bonus_list, plist)]
    i = d-1
    while True:
        if sum([count_list[i] * 100*(i+1) for i in range(d)]) + sum([bonus_list[j] * clist[j] for j in range(d)]) >= g:
            if sum(count_list) < mincount:
                mincount = sum(count_list)
            break
        elif plist[i] == count_list[i]:
            bonus_list[i] = 1
            i -= 1
            continue
        elif plist[i] > count_list[i]:
            count_list[i] += 1
            continue


print(mincount)
