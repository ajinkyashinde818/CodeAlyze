import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

s = read().rstrip().decode()
ans = 0
m = len(s)
size = m // 2
cnt_ss = m - 1
cnt_s = 0
for i in range(m):
    if s[cnt_s] == s[cnt_ss]:
        if cnt_s != size:
            cnt_s += 1
        if cnt_ss != size:
            cnt_ss -= 1
    elif s[cnt_s] == 'x':
        cnt_s += 1
        ans += 1
        m += 1
    elif s[cnt_ss] == 'x':
        cnt_ss -= 1
        ans += 1
        m -= 1
    else:
        print(-1)
        exit()
    size = m // 2
    if cnt_ss == cnt_s == size:
        break
print(ans)
