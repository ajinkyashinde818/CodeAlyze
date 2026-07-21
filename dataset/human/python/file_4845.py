s = input()
t = input()
sli = list(s)
tli = list(t)
sli.sort()
tli.sort()
tli.reverse()
def tostr(lis):
    hoge = ""
    for i in lis:
        hoge += i
    return hoge
tstr = tostr(tli)
sstr = tostr(sli)
if tstr > sstr:
    print("Yes")
else:
    print("No")
