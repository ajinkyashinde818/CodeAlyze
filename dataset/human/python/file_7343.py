from collections import deque
a = input()
q = int(input())
key = [0]*len(a)
for i in range(len(a)):
    key[i] = a[i]

p = deque(key)
rev = False
for i in range(q):
    qinput = [str(x) for x in input().split()]
    if len(qinput) == 1:
        if rev:
            rev = False
        else:
            rev = True
    else:
        k = qinput[1]
        if k == "1":
            if rev:
                p.append(qinput[2])
            else:
                p.appendleft(qinput[2])
        else:
            if not rev:
                p.append(qinput[2])
            else:
                p.appendleft(qinput[2])
if rev:
    p.reverse()
print("".join(p))
