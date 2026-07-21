from collections import deque
S=input()
q=int(input())
Q=[]
state=True
ans=deque(S)
for _ in range(q):
    t = input().split()
    if t[0] == "1":
        Q.append(int(t[0]))
    elif t[0] == "2":
        Q.append((int(t[0]),int(t[1]),t[2]))
for que in Q:
    if que == 1:
        state = not state
    else:
        if state:
            if que[1] == 1:
                ans.appendleft(que[2])
            else:
                ans.append(que[2])
        else:
            if que[1] == 2:
                ans.appendleft(que[2])
            else:
                ans.append(que[2])
anss=""
if not state:
    while len(ans) >0:
        anss += ans.pop()
else:
    while len(ans) >0:
        anss += ans.popleft()
print(anss)
