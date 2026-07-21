from collections import deque
S=input()
S_list=deque()
for k in range(len(S)):
    S_list.append(S[k])
Q=int(input())
kouho=[input().split() for i in range(Q)]
"""for i in range(Q):
    kari=input().split()
    kouho.append(kari)"""
hanten=[]
count=0
flaag=["sonomama","hantai"]

for j in range(Q):
    flag=flaag[count%2]
    if kouho[j][0]=="1":
        count+=1
    else:
        if flag=="sonomama":
            if kouho[j][1]=="1":
                S_list.appendleft(kouho[j][2])
            else:
                S_list.append(kouho[j][2])
        else:
            if kouho[j][1]!="1":
                S_list.appendleft(kouho[j][2])
            else:
                S_list.append(kouho[j][2])
for k in range(count%2):
    S_list.reverse()
print(*S_list,sep="")
