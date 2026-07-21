import sys


def judge(s):
    if s[:6] == t4:
        s2 = s[6:]
    elif s[:5] == t1 or s[:5] == t3:
        s2 = s[5:]
    elif s[:7] == t2:
        s2 = s[7:]
    else:
        s2 = "AAAAA"
    return s2


s = input()
s = s[::-1]

t1 = "maerd"
t2 = "remaerd"
t3 = "esare"
t4 = "resare"

for i in range(100000):
    length = len(s)
    if length == 5 or length == 6 or length == 7:
        if s == t1 or s == t2 or s == t3 or s == t4:
            print("YES")
            sys.exit()
        else:
            print("NO")
            sys.exit()

    ss = judge(s)
    if 0 == len(ss):
        print("YES")
        sys.exit()
    s = ss
