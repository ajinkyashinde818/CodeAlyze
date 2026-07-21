import sys
t = input()

flont = []
back = []

if len(t) == 1:
    flont = [t[0]]
else:
    flont = list(reversed(t[:-1]))
    back = [t[-1]]
q = int(input())
for i in range(q):
    s = input().split()
    if int(s[0]) == 1:
        sw = flont
        flont = back
        back = sw
    else:
        f = int(s[1])
        c = s[2]
        if f == 1:
            flont.append(c)
        else:
            back.append(c)
[sys.stdout.write(i) for i in list(reversed(flont))]
[sys.stdout.write(i) for i in back]
print("")
