import math
import sys

m=10**9 + 7 
sys.setrecursionlimit(1000010)
(N, K, S) = list(map(int,input().split()))
ans = [S for _ in range(K)]
if S != 10 ** 9: 
    ans[len(ans):len(ans)]= [10 ** 9  for _ in range(N-K)]
else:
    ans[len(ans):len(ans)]= [1  for _ in range(N-K)]
print(' '.join(list(map(str,ans))))
exit(0)
