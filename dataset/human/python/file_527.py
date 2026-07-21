import bisect

n = int(input())
a = sorted(list(map(int, input().split())))
i = bisect.bisect_left(a,0)
if i % 2 == 0:
    ans = abs(sum(a[:i]))+sum(a[i:])
else:
    if i == n:
        ans = abs(sum(a[:i-1]))+a[i-1]
    else:
        ans = abs(sum(a[:i-1]))+abs(a[i]+a[i-1])+sum(a[i+1:])
print(ans)
