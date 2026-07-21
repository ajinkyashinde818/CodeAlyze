from collections import deque

s = deque(list(map(str, input().rstrip())))
q = int(input())

state = 1
for _ in range(q):
    li = list(map(str, input().split()))
    if li[0] == "1":
        state *= -1
    elif (li[1] == "1" and state == 1) or (li[1] == "2" and state == -1):
        s.appendleft(li[2])
    else:
        s.append(li[2])

if state == -1:
    s.reverse()

print("".join(s))
