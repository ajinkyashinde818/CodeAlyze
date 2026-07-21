from collections import defaultdict


def check():
    N,M = map(int, input().split())
    B = []
    hune = defaultdict(list)
    for _ in range(M):
        a,b = map(int, input().split())
        if a == 1:
            B.append(b)
        hune[a].append(b)
    
    for b in B:
        for goal in hune[b]:
            if goal == N:
                print('POSSIBLE')
                return
    print('IMPOSSIBLE ')
    
check()
