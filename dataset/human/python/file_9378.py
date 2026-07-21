import sys
from collections import defaultdict
N, K = list(map(int, input().split()))
A = [0] + list(map(int, input().split()))

T = defaultdict(int)

key_town = 0
count = 0

if K < 3 * (10 ** 5):
    ans = 1
    for k in range(K):
        ans = A[ans]
    print(ans)
    sys.exit(0)


T[1] = 1

now = 1
for i in range(1, len(A)):
    now = A[now]
    if T[now] == 0:
        T[now] = i + 1
    else:
        key_town = now
        count = i - T[now] + 1
        break

if count == 0:
    print(key_town)
    sys.exit(0)

k = (K - T[key_town]+1) % count

ans = key_town
for i in range(k):
    ans = A[ans]
print(ans)
