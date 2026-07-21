import numpy as np

N, K = map(int, input().split())
A = np.zeros(N+1, dtype = np.int)
A[1:] = list(map(int, input().split()))

machis = {1}

now_machi = 1
count = 0

while True:
    next_machi = A[now_machi]
    count += 1
    if next_machi in machis:
        point = next_machi
        break
    machis.add(next_machi)
    now_machi = next_machi

now_machi = point
count2 = 0
while True:
    count2 += 1
    next_machi = A[now_machi]
    if next_machi == point:
        break
    now_machi = next_machi

if K - count > 0:
    times = (K - count) % count2
    now_machi = point
    for t in range(times):
        next_machi = A[now_machi]
        now_machi = next_machi
else:
    now_machi = 1
    for k in range(K):
        next_machi = A[now_machi]
        now_machi = next_machi

print(now_machi)
