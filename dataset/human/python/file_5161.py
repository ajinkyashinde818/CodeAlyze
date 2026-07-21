def inpl(): return list(map(int, input().split()))
N, M = inpl()
a1, aN, b1, bN = set(), set(), set(), set()
for i in range(M):
    temp_a, temp_b = inpl()
    if temp_a == 1:
        a1.add(temp_b)
    elif temp_a == N:
        aN.add(temp_b)
    
    if temp_b == 1:
        b1.add(temp_a)
    elif temp_b == N:
        bN.add(temp_a)

if len(a1&bN)!=0 or len(aN&b1)!=0:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
