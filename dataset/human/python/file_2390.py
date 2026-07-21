import math
D,G = map(int,input().split())
pc = [list(map(int,input().split())) for i in range(D)]
perf = [(pc[i][0]*100*(i+1)+pc[i][1]) for i in range(D)]
bitD=2**D - 1
MIN=0
for i in range(D):
    MIN+=pc[i][0]
for i in range(bitD):
    b = bin(i)
    b = b.lstrip("0b")
    blen=len(b)
    j=0
    for j in range(D-blen):
        b="0"+b
    blist=list(b)
    k=0
    flag=0
    briflag=0
    count=0
    d=0
    for k in range(D):
        I=D-1-k
        if blist[k]=="1":
            d+=perf[I]
            count+=pc[I][0]
            if G < d:
                briflag=1
                break
        else:
            if flag == 0:
                flag+=1
                zanindex = I
            else:
                pass
    if briflag == 1:
        MIN=min(count,MIN)
    else:
        zan = math.ceil((G-d)/(100*(zanindex+1)))
        if zan <= pc[zanindex][0]:
        	count+=zan
        	MIN=min(count,MIN)
        else:
          pass
print(MIN)
