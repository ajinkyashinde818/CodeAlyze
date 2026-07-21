import sys
i = sys.stdin.read().split('\n')[:-1]
s = i[0]
a = ['', '']
r = 0
for l in i[2:]:
    if l[0] == '1':
        r ^= 1
    else:
        t, f, c = l.split()
        a[0 if f == '21'[r] else 1] += c 
if r:
    print(a[0][::-1] + s[::-1] + a[1])
else:
    print(a[1][::-1] + s + a[0])
