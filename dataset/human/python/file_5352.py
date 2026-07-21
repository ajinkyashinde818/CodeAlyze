import copy

N, M = map(int, raw_input().split())
dic = {}

for i in range(M):
    tmp = map(int, raw_input().split())
    if tmp[0] not in dic:
        dic[tmp[0]] = []
        dic[tmp[0]].append(tmp[1])
    else:
        dic[tmp[0]].append(tmp[1])
    if tmp[1] not in dic:
        dic[tmp[1]] = []
        dic[tmp[1]].append(tmp[0])
    else:
        dic[tmp[1]].append(tmp[0])

flag = 0

key1 = copy.deepcopy(dic[1])
for i in key1:
    key2 = copy.deepcopy(dic[i])
    for i in key2:
        if i == N:
            flag = 1

if flag == 1:
    print "POSSIBLE"
else:
    print "IMPOSSIBLE"
