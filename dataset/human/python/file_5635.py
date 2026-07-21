from sys import stdin
s = (stdin.readline().rstrip())
l = 0
r = 1
ans = 0

for i in range(len(s)):

    if l+r >= len(s):
        break

    if s[l] == s[-r]:
        l += 1
        r += 1

    elif s[l] == "x" and s[-r] != "x":
        ans += 1
        l += 1

    elif s[l] != "x" and s[-r] == "x":
        ans += 1
        r += 1

    else:
        ans = -1
        break

print(ans)
