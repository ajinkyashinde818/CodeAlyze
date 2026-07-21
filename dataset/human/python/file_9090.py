import sys
stdin = sys.stdin
mod = 10**9 + 7

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
sa = lambda h: [list(map(int, stdin.readline().split())) for i in range(h)]

s = ns()[::-1]
ans = "YES"

while len(s) > 1:
    if s[:5] == "maerd":
        s = s[5:]
    elif s[:7] == "remaerd":
        s = s[7:]
    elif s[:5] == "esare":
        s = s[5:]
    elif s[:6] == "resare":
        s = s[6:]
    else:
        ans = "NO"
        s = ""

print(ans)
