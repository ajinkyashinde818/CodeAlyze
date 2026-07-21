import math, sys
sys.setrecursionlimit(10**7)
d,g = map(int, input().split())
data = []
ans = 10000000
for i in range(1,d+1):
    p, c = map(int, input().split())
    data.append([i*100 , p , c])
def dfs(li):
    if len(li) == d:
        global ans
        total = 0
        candidate = 0
        for i in range(d):
            if li[i]:
                total += data[i][0] * data[i][1] + data[i][2]
                candidate += data[i][1]
        if total >= g:
            ans = min(ans, candidate)
        else:
            max_point = max([data[i] for i in range(d) if not li[i]])
            if max_point[0] * (max_point[1] - 1) + total >= g:
                candidate += math.ceil((g - total) / max_point[0])
                ans = min(ans, candidate)
    else:
        dfs(li + [False])
        dfs(li + [True])
dfs([])
print(ans)
