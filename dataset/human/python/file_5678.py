import sys

s = input()
s_no_x = s.replace('x', '')
s_no_x_inv = s_no_x[::-1]

if not s_no_x == s_no_x_inv:
    print(-1)
    sys.exit()

count = 0
l = 0
r = len(s) - 1
while l < r:
    if l >= r:
        break
    if s[l] == s[r]:
        l += 1
        r -= 1
    if not s[l] == s[r]:
        count += 1
        if s[l] == 'x':
            l += 1
        else:
            r -= 1
print(count)
