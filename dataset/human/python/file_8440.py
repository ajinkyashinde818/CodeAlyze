import sys
import itertools
k, n = map(int, sys.stdin.buffer.readline().split())
a = list(map(int, sys.stdin.buffer.readline().split()))
a.append(a[0] + k)
b, c = itertools.tee(a)
next(c)
ans = k - max(y - x for x, y in zip(b, c))
print(ans)
