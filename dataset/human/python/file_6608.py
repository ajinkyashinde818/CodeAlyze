from collections import deque
S=input()
N=int(input())
Q=[input() for i in range(N)]
T=deque(S)
cnt=0
for i in range(N):
    if Q[i][0]=="1":
        cnt+=1
    if cnt%2==0:
        if Q[i][0]=="2":
            if Q[i][2]=="1":
                T.appendleft(Q[i][4])
            if Q[i][2]=="2":
                T.append(Q[i][4])
    if cnt%2==1:
        if Q[i][0]=="2":
            if Q[i][2]=="1":
                T.append(Q[i][4])
            if Q[i][2]=="2":
                T.appendleft(Q[i][4])
if cnt%2==1:
    T.reverse()
print(''.join(T))
