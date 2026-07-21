import sys
import math

readline = sys.stdin.readline
readall = sys.stdin.read
ns = lambda: readline().rstrip()
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int, readline().split()))
prl = lambda x: print(*x ,sep='\n')

d,g = nm()
comp = [nl() for _ in range(d)]
ans = 10**10
check = set([i for i in range(d)])
for i in range(2**d):
    res = 0
    times = 0
    visited = set()
    for j in range(d):
        if (i >> j) & 1:
            res += 100 * (j+1)*comp[j][0] + comp[j][1]
            times += comp[j][0]
            visited.add(j)
    if res < g:
        ma = max(check-visited)
        waru =  100 * (ma+1)
        waru_times = math.ceil((g-res)/waru)
        res += 100*waru_times*waru
        if waru_times > comp[ma][0]-1 or res < g:
            continue
        times += waru_times
        if ans > times:
            ans = times
    elif res >= g:
        if ans > times:
            ans = times
print(ans)
