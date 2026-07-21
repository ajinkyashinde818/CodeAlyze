import numpy as np
n, k = map(int, input().strip().split())
as_ = np.array(list(map(int, input().strip().split())))
as_ -= 1


first_visited = [-1] * n

now = 0
num_teleport = 0
while True:
    if first_visited[now] == -1:
        first_visited[now] = num_teleport
    else:
        # ループを発見した
        loop_length = num_teleport - first_visited[now]
        loop_start_point = now
        time_to_start_point = first_visited[now]
        break

    now = as_[now]
    num_teleport += 1


now2 = 0
if k > time_to_start_point:
    k -= time_to_start_point
    k %= loop_length
    now2 = loop_start_point

for i in range(k):
    now2 = as_[now2]

print(now2 + 1)
