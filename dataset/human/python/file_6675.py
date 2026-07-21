from collections import deque
d = deque()

S = input()
Q = int(input())
d.extend(S)




front = True

for i in range(Q):
    inp = input().split()
    if inp[0] == '1':
        front = not front
    else:
        F = int(inp[1])
        C = inp[2]
        if F == 1:
            if front:
                d.appendleft(C)
            else:
                d.append(C)
        elif F == 2:
            if front:
                d.append(C)
            else:
                d.appendleft(C)

if not front:
    d.reverse()

d_list = list(d)
str = "".join(d_list)

print(str)
