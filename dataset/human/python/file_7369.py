S=input()
Q_num = int(input())
Q=[]
for _ in range(Q_num):
    Q.append(list(input().split()))
from collections import deque
sento = deque()
matsubi = deque()
mirror_num=0
for q in Q:
    t=q[0]
    if t=='1':
        mirror_num+=1
        continue

    f=int(q[1])
    c=q[2]
    # 反転が偶数回なら反転は無視できる
    if int(mirror_num%2)==0:
        if f==1:
            sento.appendleft(c)
            continue
        matsubi.append(c)
        continue

    if f==1:
        matsubi.append(c)
        continue
    sento.appendleft(c)
    continue

sento = ''.join(sento)
matsubi = ''.join(matsubi)
S_result = sento+S+matsubi
if mirror_num%2==1:
    S_result = S_result[::-1]
print(S_result)
