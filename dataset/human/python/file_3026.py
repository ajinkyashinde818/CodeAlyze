N=int(input())
nn=N
import math
sq=round(math.sqrt(N))+1

i=2
ans=0
count1=0
count2=1
while sq>=i:
    if nn%i==0:
        nn//=i
        count1+=1
        if count1==count2:
            ans+=1
            count2+=1
            count1=0
    else:
        i+=1
        count1=0
        count2=1

if nn>sq:
    ans+=1

print(ans)
