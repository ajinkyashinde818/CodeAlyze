from collections import deque

s = input()
d = deque(s)
q = int(input())

rev = False

for i in range(q):
    inp = input()
    if inp == '1':
        rev = True if rev == False else False
    else:
        n = inp.split()[1]
        t = inp.split()[2]
        if n == '1':
            d.append(t) if rev == True else d.appendleft(t)
        else:
            d.appendleft(t) if rev == True else d.append(t)

if rev == True:
    d.reverse()

print(''.join(d))
