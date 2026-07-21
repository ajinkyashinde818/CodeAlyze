import sys
s = str(input())
t = str(input())
sl = list(s)
tl = list(t)
sl.sort()
tl.sort()
tl = tl[::-1]
a = "".join(sl)
b = "".join(tl)
if a == b:
    print("No")
    sys.exit()
ls = [a,b]
new = sorted(ls)
if ls[0] == new[0]:
    print("Yes")
else:
    print("No")
