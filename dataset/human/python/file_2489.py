D, G = map(int, input().split())
Q = []
for i in range(D):
    p, c = map(int, input().split())
    Q.append([p, c])

def solve(G, i):
    if i < 0:
        return 10**9
    
    n = min(G//(100*(i+1)), Q[i][0])
    
    p = 100 * (i+1) * n
    if n == Q[i][0]:
        p += Q[i][1]
    
    if p < G:
        ans = n + solve(G-p, i-1)
    else:
        ans = n
    return min(ans, solve(G, i-1))

print(solve(G, D-1))
