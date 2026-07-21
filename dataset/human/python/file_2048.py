import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n = int(input())
s = input()
from collections import Counter
c = Counter(s)
M = 10**9+7
ans = 1
for k,v in c.items():
    ans *= (v+1)
    ans %= M
ans -= 1
print(ans%M)
