from collections import defaultdict as dd
from collections import Counter
from pprint import pprint as pp

YN = {True: 'Yes', False: 'No'}
ri = lambda: int(input())
ria = lambda: list(map(int, input().split()))
rian = lambda n: [ria() for _ in range(n)]
rs = lambda: input()
rsa = lambda: input().split()
rsn = lambda n: [rs() for _ in range(n)]

S = rs()
print(YN[''.join(sorted(S)) == 'abc'])
