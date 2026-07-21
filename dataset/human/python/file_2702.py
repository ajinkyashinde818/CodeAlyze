d,g = map(int,input().split())
import math
pc = []
for i in range(d):
    pc.append(list(map(int,input().split())))
ans = 10000
for i in range(2**d):
    score = 0
    num = 0
    for j in range(d):
        if i>>j & 1 == 1:
            score += pc[j][0]*(j+1)*100+pc[j][1]
            num += pc[j][0]
    for j in range(d-1,-1,-1):
        if i>>j & 1 == 0:
            if g>score:
                so = math.ceil((g-score)/((j+1)*100))
                if so < pc[j][0]:
                    ans = min(ans,num+so)
            else:
                ans = min(ans,num)
        if g<=score:
            ans = min(ans,num)
print(ans)
