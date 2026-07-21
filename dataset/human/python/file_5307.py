import bisect
n,m = map(int,input().split())
a = []
b = []
ans = 'IMPOSSIBLE'
for _ in range(m):
    a1,b1 = map(int,input().split())
    a.append(a1)
    b.append(b1)
c = sorted(zip(a,b))
a.sort()
for i in range(m):
    if c[i][0] == 1:
        tmp1 = bisect.bisect_left(a,c[i][1])
        tmp2 = bisect.bisect_right(a,c[i][1])
        for j in range(tmp1,tmp2):
            if c[j][1] == n:
                ans = 'POSSIBLE'
print(ans)
