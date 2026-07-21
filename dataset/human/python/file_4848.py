import sys
s = sorted(input())
t = sorted(input(),reverse=True)
N = min(len(s),len(t))

for i in range(N):
    if s[i] > t[i]:
        print('No')
        sys.exit()
    elif s[i] < t[i]:
        print('Yes')
        sys.exit()
if len(s) < len(t):
    print('Yes')
else:
    print('No')
