from collections import deque

d = deque()
S = input()
d.append(S)
Q = int(input())
Flag = True
 
for i in range(Q):
    Query = input()
    if Query[0] == "1":
        Flag = not Flag
    else:
        QueryList = Query.split()
        if Flag:
            if QueryList[1] =="1":
                d.appendleft(QueryList[2])
            else:
                d.append(QueryList[2])
        else:
            if QueryList[1] =="2":
                d.appendleft(QueryList[2])
            else:
                d.append(QueryList[2])

d_string = "".join(list(d))

if not Flag:
    d_string = d_string[::-1]    
print(d_string)
