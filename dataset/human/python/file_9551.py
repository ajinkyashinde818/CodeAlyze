def func(x):
    return int(x)-1
N, K = list(map(int, input().split()))
A = list(map(func, input().split()))



now = 0
past = []
past_set = set()

for i in range(N):
    if now in past_set:
        break
    past.append(now)
    past_set.add(now)
    now = A[now]


i_loop = past.index(now)
loop = past[i_loop:]
if K >= i_loop:
    print(loop[(K-i_loop) % len(loop)] +1)
else:
    print(past[K] +1)
