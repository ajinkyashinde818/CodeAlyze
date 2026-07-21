from collections import deque

s = deque(list(input()))
n = int(input())
h = 1
hantensuu = 0

def change(flag):
    if flag==1:
        return 2
    else:
        return 1

for i in range(n):
    inputs = list(input().split())
    t = int(inputs[0])

    if len(inputs) == 3:
        f = int(inputs[1])
        c = inputs[2]
    if t == 1:
        h = change(h)
        hantensuu += 1
    if t == 2:
        if (f == 1 and h == 1) or (f==2 and h==2):
            s.appendleft(c)
        if (f == 2 and h == 1) or (f==1 and h ==2):
            s.append(c)
    
if hantensuu%2 !=0:
    s.reverse()

print("".join(s))
