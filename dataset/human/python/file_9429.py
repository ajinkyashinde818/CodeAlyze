from collections import deque

n, k = map(int, input().split())
array = [int(x) - 1 for x in input().split()]
count = [-1 for x in range(n)]

now = 0
count[now] = 0
queue = deque()
queue.append(now)
dag = False
dag_start = -1
dag_end = -1
while len(queue) != 0:
    now = queue.pop()
    next_index = array[now]
    if count[next_index] != -1:
        dag = True
        dag_start = next_index
        dag_end = now
        break
    count[next_index] = count[now] + 1
    queue.append(next_index)

if count[dag_start] >= k:
    for i in range(n):
        if count[i] == k:
            print(i + 1)
            exit()
now = dag_start
d = [now]
while now != dag_end:
    d.append(array[now])
    now = array[now]
print(d[(k - count[dag_start]) % len(d)] + 1)
