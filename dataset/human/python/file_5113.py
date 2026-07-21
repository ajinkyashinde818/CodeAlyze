import collections
N, M = map(int, input().split())
ablist = []
hublist1 = []
hublistN = []
work = []
for i in range(M):
    ab = tuple(map(int, input().split()))
    ablist.append(ab)
    if N in ab:
        if ab[0] == N:
            hublistN.append(ab[1])
        else:
            hublistN.append(ab[0])

    if 1 in ab:
        if ab[0] == 1:
            hublist1.append(ab[1])
        else:
            hublist1.append(ab[0])
            
work = hublist1 + hublistN
c = collections.Counter(work)
if 2 in c.values():
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
# print(ablist)
# print(hublist1)
# print(hublistN)
# print(work)
