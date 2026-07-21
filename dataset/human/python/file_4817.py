import sys

s = sorted(input())
t = sorted(input(), reverse=True)
l = len(s)
m = len(t)
n = min(l,m)

for i in range(n):
    if ord(s[i]) < ord(t[i]):
        print('Yes')
        sys.exit()
    if ord(s[i]) > ord(t[i]):
        print('No')
        sys.exit()

if l < m:
    print('Yes')
if l >= m:
    print('No')
