s = list(input())
t = list(input())

s.sort()
t.sort()
t = t[::-1]

import sys

for i, j in zip(s, t):
    if j > i:
        print('Yes')
        sys.exit(0)

if len(s) < len(t):
    for i in s:
        if i not in t:
            print('No')
            sys.exit(0)

    print('Yes')
else:
    print('No')
