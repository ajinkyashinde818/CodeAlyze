import sys
s = input()
t = s.replace('x', '')
if t != t[::-1]:
    print(-1)
    sys.exit()
if not t:
    print(0)
    sys.exit()
H = []
ctr = 0
for i in s:
    if i != 'x':
        H.append(ctr)
        ctr = 0
        continue
    ctr += 1
H.append(ctr)
print(sum([abs(i-j) for i, j in zip(H, H[::-1])])//2)
