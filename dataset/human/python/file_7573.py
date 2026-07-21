import collections as co
S=input()
Q=int(input())
count=0
back=str()
front=str()
judge=True
for i in range(Q):
    a=list(map(str,input().split()))   
    if  int(a[0])==1:
        if judge==True:
            judge=False
        else:
            judge=True
    elif int(a[0])==2 and int(a[1])==1:
        if judge==True:
            front=a[2]+front
        if judge==False:
            back=back+a[2]
    else:
        if judge==True:
            back=back+a[2]
        if judge==False:
            front=a[2]+front
    a.clear
if judge==True:
    S=front+S+back
if judge==False:
    S=front+S+back
    S=S[::-1]
print(S)
