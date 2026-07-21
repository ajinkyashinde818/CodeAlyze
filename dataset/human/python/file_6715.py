from collections import deque

s = deque(input().strip())
q = int(input())

reverseFlag = 0

for _ in range(q):
    query = input().strip()
    if query[0] == "1":
        reverseFlag = 1 - reverseFlag
    else:
        lf = reverseFlag + int(query[2])
        if lf % 2 == 0:
            s.append(query[4])
        else:
            s.appendleft(query[4])

if reverseFlag == 1:
    s.reverse()
print("".join(s))
