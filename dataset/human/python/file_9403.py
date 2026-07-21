DEBUG = False

import time

N, K = map(int, input().split())
A = [int(i)-1 for i in input().split()]

visited = [False] * N
next = A[0]
visited[0] = True
K -= 1
while not visited[next]:
    if DEBUG:
        print("K: {}, next: {}".format(K, next))
        print("visited: {}".format(visited))
        time.sleep(0.1)
    if K == 0:
        print(next+1)
        exit()
    visited[next] = True
    next = A[next]
    K -= 1

K -= 1
now = next
count = 1
next = A[next]
while now != next:
    next = A[next]
    count += 1
if DEBUG:
    print("count: {}".format(count))

K %= count

if DEBUG:
    print("now: {}, count: {}, K: {}".format(now, count, K))

while K > 0:
    if DEBUG:
        print("now: {}".format(now))
    now = A[now]
    K -= 1

print(A[now]+1)
