import sys
s = list(input())
t = list(input())
s.sort()
t.sort()
for x, y in zip(s, t[::-1]):
    if x > y:
        print('No')
        sys.exit()
    elif x == y:
        continue
    else:
        print('Yes')
        sys.exit()
if len(s) < len(t):
    print('Yes')
else:
    print('No')
