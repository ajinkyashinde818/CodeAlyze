import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
s = readline().rstrip().decode('utf-8')

t = ""
for i in s:
    if not i == "x":
        t += i

if t[::] != t[::-1]:
    print(-1)

else:
    ans = 0
    left,right = 0,len(s)-1
    while True:
        if right - left <= 0:
            break
        if s[left] == "x" and s[right] != "x":
            ans += 1
            left += 1
        elif s[left] != "x" and s[right] == "x":
            ans += 1
            right -= 1
        else:
            left += 1
            right -= 1
    print(ans)
