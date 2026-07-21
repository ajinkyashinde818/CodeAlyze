import sys
import itertools
input = sys.stdin.readline

d, g = map(int, input().split())
pc = []
ans = []
bit = list(itertools.product([0, 1], repeat=d))
cnt_v = 0
cnt = 0

for i in range(d):
    p, c = map(int, input().split())
    pc.append([p, c])

for i in range(2 ** d):
    for j in range(d):
        if bit[i][j] == 1:
            p = pc[j][0]
            c = pc[j][1]
            p_index = j + 1
            cnt_v += p * 100 * p_index + c
            cnt += p

    if cnt_v >= g:
        ans.append(cnt)

    else:
        for j in range(d):
            cnt_check = cnt_v
            if bit[i][j] == 0:
                p = pc[j][0]
                p_index = j + 1

                for k in range(p):
                    if cnt_check >= g:
                        cnt += k
                        ans.append(cnt)
                        cnt -= k
                        break

                    cnt_check += 100 * p_index
    cnt = 0
    cnt_v = 0

print(min(ans))
