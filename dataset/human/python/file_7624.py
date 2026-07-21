from collections import deque
s = deque(list(input()))
q = int(input())
sento = 0
for i in range(q):
    line = list(input().split(" "))
    if line[0] == "1":
        sento += 1
    elif line[1] == "1":
        if sento % 2 == 0:
            s.appendleft(line[2])
        else:
            s.append(line[2])
    else:
        if sento % 2 == 0:
            s.append(line[2])
        else:
            s.appendleft(line[2])
if sento % 2 ==1:
    s.reverse()
for i in range(len(s)):
    print(s[i],end ="")
print()
