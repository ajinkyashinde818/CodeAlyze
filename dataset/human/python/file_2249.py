from math import ceil
D,G=map(int,input().split())
pc=[]
ans=[]
for _ in range(D):
    pc.append(list(map(int,input().split())))

for n in range(2**D):
    X=format(n,'b').zfill(D)
    Sum=0
    solved=0
    for k in range(D):
        if X[k]=="1":
             Sum+=100*(k+1)*pc[k][0]+pc[k][1]
             solved+=pc[k][0]
    if Sum>=G:
        ans.append(solved)
    else:
        for i in range(D):
            if X[D-i-1]=="1":
                pass
            else:
                if Sum+(pc[D-i-1][0]-1)*100*(D-i)<G:
                    pass
                else:
                    ans.append(solved+ceil((G-Sum)/(100*(D-i))))

print(min(ans))
