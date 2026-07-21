from collections import deque
 
s = input()
q = int(input())
 
query = [input().split() for i in range(q)]
 
a = deque([s])
 
flag = True
 
for i in range(q):
    if query[i][0] == "1":
        flag = not(flag)
    else:
        if (query[i][1] == "1" and flag) or (query[i][1] != "1" and not(flag)):
            a.appendleft(query[i][2])
        else:
            a.append(query[i][2])
 
b = "".join(a)
if not(flag):
    b = b[::-1]
 
print(b)
