from sys import exit

n, m = map(int, input().split())

cnt = [0] * n
for _ in range(m):
    a, b = map(int, input().split())
    if a == 1 or a == n:
        cnt[b-1] += 1
    elif b == 1 or b == n:
        cnt[a-1] += 1

for c in cnt:
    if c == 2:
        print('POSSIBLE')
        exit()

print('IMPOSSIBLE')
