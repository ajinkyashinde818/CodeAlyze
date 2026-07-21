import sys
import time

N, K = map(int, input().split())
town_list = list(map(int, input().split()))

queue = {}

start = -1
count = 1

now_town = 1

for i in range(K):
    if town_list[now_town - 1] in queue:
        start = town_list[now_town - 1]
        break
    queue[town_list[now_town - 1]] = count
    now_town = town_list[now_town - 1]
    count += 1

if start == -1:
    print(now_town)
    sys.exit()

roop = len(queue) - (queue[start] - 1)
before_len = queue[start]

print(list(queue.keys())[(K - before_len) % roop + before_len - 1])
