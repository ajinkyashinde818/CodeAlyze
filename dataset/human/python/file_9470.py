from collections import defaultdict

graph = defaultdict(int)
N, K =list(map(int, input().split())) 
arr = list(map(int, input().split()))
for i, v in enumerate(arr):
    graph[i+1] = v

if graph[1] == 1:
    print(1)
    exit()

cnt = 1
cur = graph[1]
# cnt2node -> cnt2node
# node2cnt
cnt2node, node2cnt = defaultdict(int), defaultdict(int)
cnt2node[0], cnt2node[1] = 1, cur
node2cnt[1], node2cnt[cur] = 0, 1
while True:
    cur = graph[cur]
    cnt += 1
    if cur in node2cnt:
        break
    else:
        cnt2node[cnt] = cur
        node2cnt[cur] = cnt
        
first = node2cnt[cur]
if K <= first:
    print(cnt2node[K])
else:
    mod = (K - first) % (cnt - first)
    print(cnt2node[first + mod])
