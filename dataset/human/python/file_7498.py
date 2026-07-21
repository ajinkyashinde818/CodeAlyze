import copy

S=input()
Q=int(input())
Query=[]
temp=[]

revflag=0
sbef=[]
saft=[]

for i in range(Q):
    temp=input().split()
    if len(temp) ==1:
        revflag += 1
    else:
        if (revflag + int(temp[1])-1 )%2 == 0:
            sbef.append(temp[2])
        else:
            saft.append(temp[2])

ans=""

for i in range(len(sbef)):
    ans+=sbef[len(sbef)-i-1]

ans += S
for i in range(len(saft)):
    ans+=saft[i]

tmp=""
tmp2 = copy.copy(ans)


if revflag%2 ==1:
    for i in range(len(ans)):
        tmp+=tmp2[len(ans)-i-1]
    ans=tmp


print(ans)
