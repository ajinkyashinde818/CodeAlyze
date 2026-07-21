N=int(input())

import sys

if N==1:
    print("Yes")
    print(2)
    print(1,1)
    print(1,1)
    sys.exit()


ANSLIST=[]


ANS=0
x=2
while ANS<=10**5:
   ANS= (1+x)*x//2
   ANSLIST.append(ANS)
   x+=1

if N in ANSLIST:
    print("Yes")
    x=ANSLIST.index(N)+2

    print(x+1)
    ANS=[[] for i in range(x+1)]


    LIST=[]
    y=1
    z=x
    while z>=0:
        LIST.append(y)
        y+=z
        z-=1

    #print(LIST)

    for j in range(x):
        for k in range(x-j):
            ANS[j].append(LIST[j]+k)
            ANS[j+k+1].append(LIST[j]+k)

    for i in range(x+1):
        print(x,end=" ")
        for j in range(x):
            print(ANS[i][j],end=" ")
        print()


else:
    print("No")
