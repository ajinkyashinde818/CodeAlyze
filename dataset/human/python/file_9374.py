N, K = map(int, input().split())
A = list(map(int, input().split()))

cnt = [0]*N
town = 1
for i in range(K):
    if cnt[town-1] ==1:
        break

    cnt[town-1] += 1
    town = A[town-1]


ans1 = sum(cnt)

import copy
town2 = copy.deepcopy(town)

cnt2 = [0]*N

for i in range(K):
    if cnt2[town2-1] ==1:
        break

    cnt2[town2-1] += 1
    town2 = A[town2-1]
    
ans2 = sum(cnt2)

if K <= 10**8:
    town4 = 1
    for i in range(K):
        town4 = A[town4-1]
    print(town4)
else:
    town3 = 1
    cnt3=[0]*N
    K2 = ((K-(ans1-ans2))%(ans2))+(ans1-ans2)
    for i in range(K2):
        if cnt3[town3-1] ==1:
            break

        cnt[town3-1] += 1
        town3 = A[town3-1]
    print(town3)
