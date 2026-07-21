import collections

s = str(input())
t = str(input())
f = s + t
c = collections.Counter(f)
red = False
if len(c) == 1:
    if len(s) < len(t):
        red = True

for i in s:
    for k in t:
        if i < k:
            red = True
            break
if red:
    print("Yes")
else:
    print("No")
