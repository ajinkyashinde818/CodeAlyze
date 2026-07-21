import sys
s = sorted(list(str(input())))
t = sorted(list(str(input())), reverse = True)
u = min(len(s), len(t))
for i in range(min(len(s), len(t))):
    if s[i] < t[i]:
        print('Yes')
        sys.exit()
    if s[i] > t[i]:
        print('No')
        sys.exit()
if s[0:u] == t[0:u] and len(s) < len(t):
    print('Yes')
elif s[0:u] == t[0:u] and len(s) >= len(t):
    print('No')
