import sys
input = sys.stdin.readline

d,g = map(int,input().split())
p = []
s = []
for i in range(d):
    x,y = map(int,input().split())
    p.append(x)
    s.append(100*(i+1)*x+y)

ans = 10**10
for i in range(1<<(d+1)):
    cnt = 0
    res = 0
    tank = []
    for j in range(d):
        if (i>>j)&1 == 1:
            cnt += s[j]
            res += p[j]
        else:
            tank.append([100*(j+1),p[j]])
    if cnt >= g:
        ans = min(ans,res)
    else:
        while cnt < g and tank[-1][1] > 0:
            cnt += tank[-1][0]
            tank[-1][1] -= 1
            res += 1
        if cnt >= g:
            ans = min(ans,res)
print(ans)
