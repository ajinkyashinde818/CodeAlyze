d,g=map(int,input().split())
s=[list(map(int,input().split()))for i in range(d)]
def dfs(d,g):
    if d==0:
        return 1e9
    l=min(g//(d*100),s[d-1][0])
    k=100*d*l
    if l==s[d-1][0]:
        k+=s[d-1][1]
    if k<g:
        l+=dfs(d-1,g-k)
    return min(l,dfs(d-1,g))
print(dfs(d,g))
