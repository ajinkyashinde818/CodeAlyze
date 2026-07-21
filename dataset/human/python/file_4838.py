import collections

s = input()
t = input()
s = ''.join(sorted(s))
t = ''.join(sorted(t, reverse=True))

for i in range(min(len(s), len(t))):
    if ord(s[i]) > ord(t[i]):
        print('No')
        break
    elif ord(s[i]) < ord(t[i]):
        print('Yes')
        break
    else:
        pass
else:
    if len(s) < len(t):
        print('Yes')
    else:
        print('No')
