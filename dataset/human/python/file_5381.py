from operator import itemgetter
from collections import Counter
N,M = map(int,input().split())
ab = {tuple(map(int,input().split())) for _ in range(M)}
if M == 1:
    print('IMPOSSIBLE')
    exit()
ab = [i[1] if i[0] == 1 else i[0] for i in ab if i[0] == 1 or i[1] == N]
c = Counter(ab)
if c.most_common(1)[0][1] == 2:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
