from collections import defaultdict

N, K = map(int, input().split())
A = list(map(int, input().split()))

memo_first = defaultdict(int)
memo_cnt = defaultdict(int)

current = 1
cnt = 1

while K != 0:
    if memo_first[current]==0:
        memo_first[current] = cnt
    if memo_first[current] != 0 & memo_cnt[current]==0:
        memo_cnt[current] = cnt - memo_first[current]
    if memo_cnt[current] != 0:
        roop = K // memo_cnt[current]
        K = K - roop * memo_cnt[current]
    current = A[current - 1]
    K -= 1
    cnt += 1

print(current)
