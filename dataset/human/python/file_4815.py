import sys
s = list(input())
t = list(input())

if not (1 <= len(s) <= 100 and 1 <= len(t) <= 100):
    sys.exit()

if s == t:
    print('No')
    sys.exit()

s.sort()
t.sort(reverse=True)
result = []
result.append(''.join(s))
result.append(''.join(t))
result.sort()

if result[0] == ''.join(s):
    print('Yes')
else:
    print('No')
