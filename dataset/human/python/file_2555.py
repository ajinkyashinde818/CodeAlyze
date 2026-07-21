import sys
input = sys.stdin.readline

d, g = [int(x) for x in input().split()]
pc = [[int(x) for x in input().split()] for _ in range(d)]

ans = float("inf")

for i in range(2 ** d):
    s = set() # コンプリートボーナスをもらう
    for j in range(d):
        if (i >> j) & 1:
            s.add(j)
    cnt = 0
    total = 0
    for k in s:
        cnt += pc[k][0]
        total += (k + 1)*pc[k][0]*100 + pc[k][1]
    if total >= g:
        ans = min(ans, cnt)
        continue
    for l in range(d - 1, -1, -1):
        flag = 0
        if l in s:
            continue
        for m in range(1, pc[l][0]):
            total += (l + 1) * 100
            cnt += 1
            if total >= g:
                flag = 1
                break
        if flag:
            break
    if total >= g:
        ans = min(ans, cnt)

print(ans)
