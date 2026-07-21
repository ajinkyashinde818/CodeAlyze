import sys

s = sorted(input())
t = sorted(input(), reverse=True)

for c_s, c_t in zip(s, t):
    if c_s < c_t:
        print('Yes')
        sys.exit()
    elif c_s > c_t:
        print('No')
        sys.exit()

if len(s) < len(t):
    print('Yes')
else:
    print('No')
