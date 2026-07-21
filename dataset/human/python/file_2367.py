import math

D,G = list(map(int,input().split()))
lst = [list(map(int,input().split())) for i in range(D)]
for i in range(10-D):
    lst.append([0,0]) 
lst.insert(0,[])

ans = 1000
for i in range(1024):
    bin_i = format(i,'b').zfill(11)
    tmp = G
    solved = 0
    for j in range(1,11):
        if bin_i[j] == "1":
            tmp -= lst[j][0]*j*100 + lst[j][1]
            solved += lst[j][0]
    if 0 < tmp:
        for j in range(10,0,-1):
            if bin_i[j] == "0" and lst[j][0] != 0:
                if tmp <= (lst[j][0]-1)*j*100:
                    solved += math.ceil(tmp/(j*100))
                    break
        else:
            #この条件ではGを超えない
            continue
        ans = min(ans,solved)
    else:
        ans = min(ans,solved)
print(ans)
