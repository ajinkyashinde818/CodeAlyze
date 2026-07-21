D,G=map(int,input().split())
PC=[list(map(int,input().split())) for i in range(D)]


def solve(G, i):
    if i <= 0:
        return float('inf')
    n = min(G//(100*i), PC[i-1][0])
    score = 100 * i * n
    if n == PC[i-1][0]:
        score += PC[i-1][1]
    if G > score:
        n += solve(G-score, i-1)
    return min(n, solve(G, i-1))
 
 
print(solve(G, D))
