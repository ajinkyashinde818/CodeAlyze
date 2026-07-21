import sys

s = list(input())
t = list(input())
s.sort()
t.sort()
t.reverse()

for i in range(min(len(s) , len(t))):
    if ord(s[i]) < ord(t[i]):
        print("Yes")
        sys.exit()
    elif ord(s[i]) > ord(t[i]):
        print("No")
        sys.exit()

print("Yes") if len(s) < len(t) else print("No")
