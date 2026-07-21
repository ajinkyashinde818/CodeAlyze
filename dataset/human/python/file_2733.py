d, g = map(int, input().split())
PC = [0] + [[i for i in map(int, input().split())] for i in range(d)]

def dfs(g, i):
    if i == 0:
        return 10 ** 12
    
    cnt = min(g // (100 * i), PC[i][0])
    score = cnt * 100 * i
    
    if cnt == PC[i][0]:
        score += PC[i][1]
        
    if g > score:
        cnt += dfs(g - score, i - 1)
    
    return min(cnt, dfs(g, i - 1))

print(dfs(g, d))
