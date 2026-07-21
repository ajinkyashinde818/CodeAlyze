import sys
readline = sys.stdin.readline
s = readline().strip()
n = int(readline())
rev = False
h = []
t = []
for i in range(n):
    q = readline()
    if q.startswith("1"):
        rev = not rev
    if q.startswith("2 1"):
        if not rev:
            h.append(q[-2])
        else:
            t.append(q[-2])
    if q.startswith("2 2"):
        if not rev:
            t.append(q[-2])
        else:
            h.append(q[-2])
s = "".join(h[::-1]) + s + "".join(t)
if rev:
    print(s[::-1])
else:
    print(s)
