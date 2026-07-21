import sys
l = raw_input().split()
N = int(l[0])
M = int(l[1])
nlist = []
list1 = []
for i in range(0, M):
    tmp = raw_input().split()
    a = int(tmp[0])
    b = int(tmp[1])
    if a == 1:
        list1.append(b)
        continue
    if b == N:
        nlist.append(a)
        continue
matched_list = list(set(list1) & set(nlist))
if len(matched_list) == 0:
    print('IMPOSSIBLE')
else:
    print('POSSIBLE')
