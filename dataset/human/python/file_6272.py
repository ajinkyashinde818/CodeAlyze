import sys

input = sys.stdin.readline
N = list(map(int, input().strip()))[::-1]
ans = 0
before = 0
L = len(N)
for i, c in enumerate(N):
    n = c + before
    if 0 <= n < 5:
        before = 0
        ans += n
    elif n == 5:
        if i+1 == L:
            before = 0
            ans += n
            continue
        if N[i+1] < 5:
            before = 0
            ans += n
        else:
            ans += 10-n
            before = 1
    else:
        ans += 10-n
        before = 1
print(ans + before)
