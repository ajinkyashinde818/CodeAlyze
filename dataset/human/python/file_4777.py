import sys

s = sorted(list(input()))
t = sorted(list(input()), reverse=True)

st = "".join(s)
tt = "".join(t)

if st == tt:
    print("No")
    sys.exit()

stlist = [st, tt]
stlist = sorted(stlist)
if stlist[0] == st:
    print("Yes")
else:
    print("No")
