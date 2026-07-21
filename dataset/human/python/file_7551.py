from collections import deque
S = deque(str(input()))
Q = int(input())
count = 0
for i in range(Q):
    tmp = list(input().split())
    if tmp[0]=="1":
        count += 1
    else:
        if tmp[1]=="1" and count%2==0 or tmp[1]=="2" and count%2==1:
            S.appendleft(tmp[2])
        elif tmp[1]=="2" and count%2==0 or tmp[1]=="1" and count%2==1:
            S.append(tmp[2])
if count%2==0:
    ans = "".join(S)
    print(ans)
else: 
    S.reverse()
    ans = "".join(S)
    print(ans)
