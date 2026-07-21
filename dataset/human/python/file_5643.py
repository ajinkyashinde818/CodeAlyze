from sys import stdin

s = stdin.readline().rstrip()

r = len(s)-1
l = 0
count = 0
while r-l > 0:
    if s[l] == s[r]:
        r -= 1
        l += 1
    elif s[l] == "x" and s[r] != "x":
        count += 1
        l += 1
    elif s[r] == "x" and s[l] != "x":
        count += 1
        r -= 1
    else:
        print(-1)
        exit()
print(count)
