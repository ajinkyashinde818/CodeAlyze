s = sorted(input())
t = sorted(input(), reverse=True)
s.append('')
t.append('')
import sys
for i,j in zip(s,t):
    if i < j:
        print('Yes')
        sys.exit()
    elif i > j:
        print('No')
        sys.exit()
print('No')
