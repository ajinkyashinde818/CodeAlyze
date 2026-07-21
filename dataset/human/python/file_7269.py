from collections import deque
s = list(input())
n = int(input())
q = deque(s)
Reverse = 0

for i in range(n):
    Input = input().split()
    if int(Input[0]) == 1:
        Reverse = abs(Reverse-1)
        continue
    else:
        if int(Input[1]) == 1:
            if Reverse == 0:
                q.appendleft(Input[2])
            else:
                q.append(Input[2])
        else:
            if Reverse == 0:
                q.append(Input[2])
            else:
                q.appendleft(Input[2])
if Reverse==1:
    q.reverse()
print(''.join(q))
