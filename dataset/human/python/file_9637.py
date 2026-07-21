N, K = map(int, input().split())
routes = list(map(int, input().split()))

otozureta = set([1])
otozureta_list = [1]

import sys
sys.setrecursionlimit(1000000)

def search(list, next):
    if not otozureta.isdisjoint(set([next])):
        return next
    else:
        otozureta.add(next)
        otozureta_list.append(next)
        return search(list, routes[next - 1])


target = search(routes, routes[0])
target_index = otozureta_list.index(target)

otozureta_list_len = len(otozureta_list)
loop_length = otozureta_list_len - target_index
loop_made_length = target_index
#print(otozureta)

if K < otozureta_list_len:
    print(otozureta_list[K])
else:

    print(otozureta_list[loop_made_length + ((K - loop_made_length) % loop_length)])
