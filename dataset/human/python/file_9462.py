import sys
n,k=map(int,input().split())
alist=list(map(int,input().split()))

vislist=[1]
visset={1}
loopflag=True
endflag=False
donek=0
ima=1

while loopflag:
    ima=alist[ima-1]
    if ima in visset:
        loopflag=False
        if ima == alist[ima-1]:
            endflag=True
    else:
        vislist.append(ima)
        visset.add(ima)

        donek+=1

        if donek == k:
            loopflag=False
            endflag=True

if endflag:
    print(ima)
    sys.exit()

loopstartindex=vislist.index(ima)
looplength=len(visset)-loopstartindex
if (k+1-loopstartindex)%looplength == 0:
    print(vislist[-1])
else:
    print(vislist[loopstartindex+(k+1-loopstartindex)%looplength-1])
