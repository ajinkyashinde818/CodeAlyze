from collections import deque
s = list(input())
q = int(input())
rv = False
fr = deque()
re = []
for i in range(q):
    t = input().split(' ')
    if t[0] == '1':
        rv = True if not rv else False
    else:
        if t[1] == '1' and not rv or t[1] == '2' and rv:
            fr.appendleft(t[2])
        else:
            if t[1] == '1' and rv or t[1] == '2' and not rv:
                re.append(t[2])
if rv:
    re.reverse()
    s.reverse()
    fr.reverse()
    print(''.join(re + s) + ''.join(fr))
else:
    print(''.join(fr) + ''.join(s + re))
