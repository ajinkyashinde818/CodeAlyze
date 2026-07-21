import math

d,g=map(int,input().split())
pclist=[]
templist=[]
for i in range(d):
	templist=[]
	templist=list(map(int,input().split()))
	templist.append(templist[0]*100*(i+1)+templist[1])
	pclist.append(templist)

promin=1000

for i in range(2**d):
    gsum=0
    prosum=0
    maxind=100
    
    for j in range(d):
        if (i >> j)& 1:
            gsum += pclist[j][2]
            prosum += pclist[j][0]
        else:
            maxind=j
            
    
    if gsum >= g:
        if prosum <= promin:
            promin=prosum
    elif (gsum + (maxind+1)*100*(pclist[maxind][0]-1))>= g:
        prosum += math.ceil((g-gsum)/((maxind+1)*100))
        if prosum <= promin:
            promin=prosum


print(promin)
