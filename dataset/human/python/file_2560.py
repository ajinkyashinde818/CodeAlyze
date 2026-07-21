import math
D,G=map(int,input().split())
PC=[list(map(int,input().split())) for i in range(D)]
zenkan=[]
def saiki(A):
    if len(A)==D:
        ans=0
        count=0
        toita=[]
        for i in range(D):
            if A[i]==1:
                ans+=PC[i][0]*(i+1)*100+PC[i][1]
                count+=PC[i][0]
                toita.append(i)
        zenkan.append([ans,count,toita])
        return ans
    for i in range(2):
        A.append(i)
        saiki(A)
        A.pop()
saiki([])
ans=[]
zenkan.sort()
for i in range(len(zenkan)):
    cost=zenkan[i][1]
    hituyo=G-zenkan[i][0]
    if zenkan[i][0]>=G:
        ans.append(cost)
        continue
    cost_kari=[]
    for j in range(D):
        if j not in zenkan[i][2]:
            if PC[j][0]*100*(j+1)>=hituyo:
                cost_kari.append(math.ceil(hituyo/(100*(j+1))))
            #print(math.ceil(hituyo/100*(j+1)),j)
    cost_kari.sort()
    if len(cost_kari)!=0:
        ans.append(cost+cost_kari[0])
    elif hituyo<=0:
        ans.append(cost)
    #print(cost_kari)
#print(zenkan)
#print(ans)
print(min(ans))
