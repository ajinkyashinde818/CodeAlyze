import numpy as np

n, k = map(int, input().split())
a_list = list(map(int, input().split()))

a_dict = {}
for from_a, to_a in enumerate(a_list):
    a_dict[from_a+1] = to_a

now = 1
a_route = [now]
a_set = set([now])
for _ in range(len(a_dict.keys())):
    now = a_dict[now]
    if now in a_set:
        start_c = now
        break
    a_set.add(now)
    a_route.append(now)
a_route = np.array(a_route)

ind = np.where(a_route==start_c)[0][0]
first_path = a_route[:ind]
a_route = a_route[ind:]

if k<=len(first_path)-1:
    print(first_path[k])
else:
    k -= len(first_path)
    print(a_route[k%len(a_route)])
