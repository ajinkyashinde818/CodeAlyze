import math
d,g=map(int,input().split())
pc=[[int(i)for i in input().split()]for _ in range(d)]
a=1000
for i in range(2**d):
    c=0
    s=0
    m=0
    for j in range(d):
        if (i>>j)&1:
            s+=(j+1)*100*pc[j][0]+pc[j][1]
            c+=pc[j][0]
        else:
            m=j
    if s>=g:
        a=min(a,c)
    elif (m+1)*100*(pc[m][0]-1)+s>=g:
        a=min(a,c+math.ceil((g-s)/((m+1)*100)))
print(a)
