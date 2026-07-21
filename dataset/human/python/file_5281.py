import bisect

n, m = map(int, input().split())
f_1 = []
t_n = []
jedge = 0
for i in range(m):
    a, b = map(int, input().split())
    if a == 1:
        f_1.append(b)
    if b == n:
        t_n.append(a)
f_1.sort()
t_n.sort()
for i in range(len(f_1)):
    p = bisect.bisect_left(t_n, f_1[i])
    if p < len(t_n)-1 and f_1[i] == t_n[p]:
        jedge = 1
        break
    elif p == len(t_n)-1 and f_1[i] == t_n[p]:
        jedge = 1
        break
if jedge == 1:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
