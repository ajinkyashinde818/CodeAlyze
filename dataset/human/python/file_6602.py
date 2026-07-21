from collections import deque
s = deque(input())
q = int(input())
lis = [list(input().split()) for _ in range(q)]
rev = 0
z = 0

for i in lis:
    if i[0] == "2":
        if (rev + int(i[1])) % 2 == 1:
            s.appendleft(i[2])
        else:
            s.append(i[2])
        z = 1
    else:
        if z == 1:
            rev += 1
        
if rev % 2 == 1:
    s = reversed(s)
print("".join(s))
