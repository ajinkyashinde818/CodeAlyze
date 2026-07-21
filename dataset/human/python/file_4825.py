from sys import stdin


s = stdin.readline().rstrip()
s = [str(i) for i in s]

t = stdin.readline().rstrip()
t = [str(i) for i in t]

if s == t:
    print("No")
    exit()
s.sort()
t.sort(reverse=True)

ns = ""
nt = ""

for i in range(len(s)):
    ns += s[i]

for i in range(len(t)):
    nt += t[i]

li = [ns,nt]

lin = sorted(li)


if lin == li:
    print("Yes")
    exit()
print("No")
