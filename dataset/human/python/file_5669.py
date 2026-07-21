import sys
s = input()
num = len(s)
l, r = 0, num-1
ans = 0

while l < r:
    if s[l] == s[r]:
        l += 1
        r -= 1
    else:
        ans += 1
        if s[l] == 'x':
            l += 1
        elif s[r] == 'x':
            r -= 1
        else:
            print(-1)
            sys.exit()
print(ans)
