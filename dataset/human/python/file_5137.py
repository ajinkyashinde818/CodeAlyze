from collections import defaultdict
d = defaultdict(set)
n, m = map(int, input().split())
for _ in range(m):
    a, b = map(int, input().split())
    d[a].add(b)


def solve(n, d):
    for a in d[1]:
        if n in d[a]:
            return 'POSSIBLE'
    return 'IMPOSSIBLE'


print(solve(n, d))
