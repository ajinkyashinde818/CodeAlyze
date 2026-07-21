import sys

s = input()

rem = []
remrev = []

for i in s:
    if i != "x":
        rem.append(i)
        remrev.append(i)

remrev.reverse()

for i in range(len(rem)):

    if rem[i] != remrev[i]:
        print (-1)
        sys.exit()

nx = 0
xnum = []

for i in s:

    if i == "x":
        nx += 1
    else:
        xnum.append(nx)
        nx = 0

xnum.append(nx)

xnc = xnum.copy()
xnc.reverse()

ans = 0

for i in range((len(xnum) + 1) // 2):

    ans += abs(xnum[i]-xnc[i])

print (ans)
