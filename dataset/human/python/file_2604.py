import itertools

d,g=map(int,input().split())
pc=[[0]*2 for i in range(d)]
for i in range(d):
    pc[i]=list(map(int,input().split()))

icntmin=10*100+1
for j in itertools.product([0,1], repeat=d):
    icnt=0
    gcnt=0
    for i in range(d):
        if j[i]==1:
            icnt+=pc[i][0]
            gcnt+=pc[i][0]*100*(i+1)+pc[i][1]
        else:
            ii=i
            
#    print("1",icnt,gcnt,j)
    if gcnt>=g:
        icntmin=min(icnt,icntmin)
        continue
    else:
        gr=g-gcnt
        k=(gr-1)//(100*(ii+1))+1
        if k<pc[ii][0]:
            icnt+=k
            gcnt+=k*100*(ii+1)
            icntmin=min(icnt,icntmin)
#    print("2",icnt,gcnt,ii,gr,k,j)
        
print(icntmin)
