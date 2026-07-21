import sys
input = sys.stdin.readline
s = list(input().rstrip())
t = list(input().rstrip())
s = sorted(s)
t = sorted(t, reverse=True)
alpha2num = lambda c: ord(c) - ord("a")
if s == t:
    print("No")
    sys.exit()
for i in range(min(len(s), len(t))):
    x, y = s[i], t[i]
    if alpha2num(x) < alpha2num(y):
        print("Yes")
        sys.exit()
    elif alpha2num(x) > alpha2num(y):
        print("No")
        sys.exit()
if len(t) > len(s):
    print("Yes")
else:
    print("No")
