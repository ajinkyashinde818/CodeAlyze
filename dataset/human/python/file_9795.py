import collections

n,k=map(int,input().split())
a=list(map(int,input().split()))
L=[1]
count=1
nowt=1
roops=0
v=[False]*n
while(True):
    if v[a[nowt-1]-1]==True:
        roops=a[nowt-1]
        break

    L.append(a[nowt-1])
    v[a[nowt-1]-1]=True
    nowt=a[nowt-1]
    count+=1

play=0
for i in range(len(L)):
    if L[i]==roops:
        break
    play+=1

rooplen=len(L)-play

if k<play:
    print(L[k])
    exit() 

ans=L[play+(k-play)%rooplen]

print(ans)
