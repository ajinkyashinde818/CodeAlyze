from math import ceil
d,g=map(int,input().split())
pc=[list(map(int,input().split())) for _ in [0]*d]
m=1000

for i in range(2**d):
    cnt=0
    s=g
    for j in range(d):
        k=(i&(2**j))>>j
        if k==1:
            s-=pc[j][0]*(j+1)*100+pc[j][1]
            cnt+=pc[j][0]
    if s<=0:
        m=min(m,cnt)
    else:
        for j in range(d-1,-1,-1):
            k=(i&(2**j))>>j
            if k==0:
                if pc[j][0]*(j+1)*100 >= s:
                    cnt+=ceil(s/((j+1)*100))
                    break
                else:
                    s-=pc[j][0]*100*(j+1)
                    cnt+=pc[j][1]
        m=min(m,cnt)
print(m)
