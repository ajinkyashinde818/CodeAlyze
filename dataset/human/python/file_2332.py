D,G=map(int, input().split())
PC=[0]+[list(map(int,input().split())) for _ in range(D)]
PC

def dfs(i,g):
    if i ==0:
        return 1e9
    m =min(g//(i*100),PC[i][0])
    s=100*i*m
    if m ==PC[i][0]:
        s+=PC[i][1]
    if s<g:
        m+=dfs(i-1,g-s)
    return min(m, dfs(i-1,g))
print(dfs(D,G))
