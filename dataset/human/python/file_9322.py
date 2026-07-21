import sys
input = sys.stdin.readline
from collections import defaultdict

(n, k), s = map(int, input().split()), list(map(int, input().split()))
x, c = [1, s[0]], 0
for i in range(n): x.append(s[x[-1] - 1])
if len(x) > k: print(x[k]); exit()
while x[c] != s[x[-1] - 1]: c += 1
print(x[((k - c) % (len(x) - c)) + c])
