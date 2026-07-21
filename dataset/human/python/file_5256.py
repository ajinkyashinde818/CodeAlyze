from collections import defaultdict

def main():
    n, m = map(int, input().split())
    edges = defaultdict(list)

    for _ in range(m):
        a, b = map(int, input().split())
        edges[a].append(b)
        edges[b].append(a)
    
    if solve(n, edges):
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')

def solve(n, edges):
    x = set(edges[1])
    y = set(edges[n])

    if x & y:
        return True
    else:
        return False

main()
