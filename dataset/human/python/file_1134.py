n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

import collections
ac = collections.Counter(a)
bc = collections.Counter(b)

for i in range(1,n+1):
    if ac[i] + bc[i] > n:
        print("No")
        exit()

from collections import defaultdict
a_right  = defaultdict(int)
b_left = defaultdict(int)

for i in range(n):
    a_right[a[i]] = i

for i in reversed(range(n)):
    b_left[b[i]] = i

sft=[0]
for dup in set(a) & set(b):
    sft.append(a_right[dup] - b_left[dup]+1)

from collections import deque
b=deque(b)
b.rotate(max(sft))
print("Yes")
print(*b)
