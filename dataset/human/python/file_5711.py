import sys
s = input()
a, b = '', ''
for i in range(len(s)):
    if s[i] != 'x':
        a += s[i]
        b = s[i] + b
if a != b:
    print(-1)
    sys.exit()
ans = 0
while len(s) != 0:
    if s[0] == s[-1]:
        s = s[1:-1]
    elif s[0] == 'x' and s[-1] == 'x':
        if len(s) == 1:
            s = ''
        else:
            s = s[1:-1]
    elif s[0] == 'x':
        s = s[1:]
        ans += 1
    elif s[-1] == 'x':
        s = s[:-1]
        ans += 1
print(ans)
