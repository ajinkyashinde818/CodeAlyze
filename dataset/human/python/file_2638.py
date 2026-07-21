from math import ceil
dg=list(map(int,input().split()))
pc=[]
ans=0
for i in range(dg[0]):
    pc.append(list(map(int,input().split())))
    ans+=pc[-1][0]
pattern=2**dg[0]
for i in range(2**dg[0]):
    for j in range(dg[0]):
        p=bin(pattern+i)[3:]
        tsum=0
        tans=0
        for k in range(dg[0]):
            if k==j:
                pass
            else:
                if p[k]=="0":
                    tsum+=(1+k)*100*pc[k][0]+pc[k][1]
                    tans+=pc[k][0]
        if tsum<dg[1]:
            dtans=min(pc[j][0]-1,ceil((dg[1]-tsum)/((1+j)*100)))
            tsum+=((1+j)*100)*dtans
            tans+=dtans
        if tans<ans and tsum>=dg[1]:
            ans=tans
print(ans)
