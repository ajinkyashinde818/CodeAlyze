from collections import deque
S = list(input())
Q = int(input())

day = deque(S)

r = False
for i in range(Q):
    x = input().split()
    
    if x[0] == "1":
        r = not r
        
    else:
        if x[1] == "1":
            if r == False :
                day.appendleft(x[2])
            else:
                day.append(x[2])
        else:
            if r == True :
                day.appendleft(x[2])
            else:
                day.append(x[2])
                
day = list(day)
        
if r:
    print("".join(day[::-1]))
else:
    print("".join(day))
