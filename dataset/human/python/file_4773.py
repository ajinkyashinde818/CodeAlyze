import sys
s = sys.stdin.readline().strip()
t = sys.stdin.readline().strip()

ss = sorted(list(s), key=lambda x: x)
tt = sorted(list(t), key=lambda x: x)[::-1]
if "".join(ss) < "".join(tt):
    print("Yes")
else:
    print("No")
