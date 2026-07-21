import sys
s = list(input())
t = list(input())
s.sort()
t.sort(reverse=True)
num = min(len(s), len(t))
for i in range(num):
    if ord(s[i]) > ord(t[i]):
        print('No')
        sys.exit()
    elif ord(s[i]) < ord(t[i]):
        print('Yes')
        sys.exit()
    elif ord(s[i]) == ord(t[i]) and i == num-1:
        if len(s) < len(t):
            print('Yes')
            sys.exit()
    elif ord(s[i]) == ord(t[i]):
        continue

print('No')
