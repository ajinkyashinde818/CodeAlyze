from sys import stdin
s = list(stdin.readline().rstrip())
q = int(stdin.readline().rstrip())
t = []
k = []
for i in range(q):
    t.append([x for x in stdin.readline().rstrip().split()])
r = 0
for i in range(q):
    if int(t[i][0]) == 1:
        if r == 1:
            r = 0
        else:
            r = 1
    else:
        if (int(t[i][1]) + r) % 2 == 0:
            s.append(t[i][2])
        else:
            k.append(t[i][2])
k = list(reversed(k))
k.extend(s)
if r == 1:
    k = list(reversed(k))
k = ''.join(k)
print(k)
