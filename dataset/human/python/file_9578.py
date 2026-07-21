from collections import defaultdict

n,k = map(int,input().split())
town_list = list(map(int,input().split()))

town_dict = dict()
for a,town in enumerate(town_list, 1):
    town_dict[a] = town


if k <= n:
    now_place = 1
    for _ in range(k):
        now_place = town_dict[now_place]

    print(now_place)

if k > n:
    now_place = 1
    visit_town = dict()
    visit_town[1] = 0
    tmp_last_visit = -1
    tmp_visit = -1
    for j in range(n):
        now_place = town_dict[now_place]

        if now_place in visit_town:
            tmp_last_visit = visit_town[now_place]
            tmp_visit = j+1
            break

        visit_town[now_place] = j+1

    if tmp_last_visit == -1:
        print(now_place)
    else:
        ans = (k-tmp_visit)%(tmp_visit-tmp_last_visit)
        
        for _ in range(ans):
            now_place = town_dict[now_place]

        print(now_place)
