from math import ceil
D,G = map(int,input().split())
para = [[i for i in map(int,input().split())] for j in range(D)]
result = []
for i in  range(2**D):
    ans = 0
    cnt = 0
    num = format(i,"b").zfill(D)
    for j in range(D,0,-1):

        if num[j-1] == "1" :
            ans += para[j-1][0] *100*j + para[j-1][1]
            cnt += para[j-1][0]
            
        else : pass

    if ans >= G :
        result.append(cnt)
    else :
        for j in range(D,0,-1):
            if num[j-1] == "1" : pass
            else : 
                if G <= ans + (para[j-1][0]-1)*100*(j):
                    cnt += ceil((G-ans)/(100*(j)))
                    result.append(cnt) 
                
print(min(result))
