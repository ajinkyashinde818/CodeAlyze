from collections import deque
Q=deque()
a=input()
Q.append(a)
q=int(input())
reverse=False
for i in range(q):
    d=input()
    if d[0]=="1": reverse= not reverse
    elif d[0]=="2":
        _, f, c=d.split()
        if f == "1":
            if reverse:
                Q.append(c)
            else:
                Q.appendleft(c)
        elif f =="2":
            if reverse:
                Q.appendleft(c)
            else:
                Q.append(c)
ans="".join(Q)
if reverse:
    ans=ans[::-1]
print(ans)
