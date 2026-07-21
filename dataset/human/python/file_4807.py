import sys
s = list(input())
s.sort()
t = list(input())
t.sort(reverse = True)
for i in range(min(len(s),len(t))):
    if ord(s[i]) < ord(t[i]):
        print("Yes")
        sys.exit()
    elif ord(s[i]) > ord(t[i]):
        print("No")
        sys.exit()
print("Yes" if len(s) < len(t) else "No")
