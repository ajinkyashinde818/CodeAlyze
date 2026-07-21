s = input()
t = input()

sorted_s = sorted(s)
sorted_t = sorted(t,reverse=True)

import sys
N = min(len(sorted_s),len(sorted_t))

for i in range(N):
    if ord(sorted_s[i]) < ord(sorted_t[i]):
        print('Yes')
        sys.exit()
    elif ord(sorted_s[i]) > ord(sorted_t[i]):
        print('No')
        sys.exit()

if len(sorted_s) < len(sorted_t):
    print('Yes')
else:
    print('No')
