from collections import defaultdict

N, K = map(int, input().split())
A = list(map(int, input().split()))

cur = 0     # 現在地
period = 0  # 繰り返し周期
rest = 0    # 繰り返し周期に入らない最初のテレポート回数
counter = defaultdict(int)   # 2回目を通るときの検出用
first_index = defaultdict(int)  # 1回目に通ったテレポート回数

counter[0] = 1
first_index[0] = 0
for i in range(1, N):
    cur = A[cur] - 1
    counter[cur] += 1
    if counter[cur] == 2:
        period = i - first_index[cur]
        rest = first_index[cur]
        break
    else:
        first_index[cur] = i
if K <= rest:
    cur = 0
    for i in range(K):
        cur = A[cur] - 1
    print(cur+1)
else:
    for i in range((K - rest) % period):
        cur = A[cur] - 1
    print(cur+1)
