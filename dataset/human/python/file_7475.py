from collections import deque
s = input()
sque = deque(s)
q = int(input())
que = [0] * q
flg = False
for i in range(q):
    que[i] = (list(map(str,input().split())))
    if(len(que[i])==3):
        if que[i][1] == '1':
            if flg:
                sque.append(que[i][2])
            else:
                sque.appendleft(que[i][2])
        else:
            if flg:
                sque.appendleft(que[i][2])
            else:
                sque.append(que[i][2])
    else:
        if flg:
            flg = False
        else:
            flg = True
if flg:
    sque.reverse()
    print("".join(list(sque)))
else:
    print("".join(list(sque)))
