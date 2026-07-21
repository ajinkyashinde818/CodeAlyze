import itertools
from operator import itemgetter

D,G = map(int,input().split())
pc = []

for i in range(D):
    p,c = list(map(int,input().split())) 
    tmp = (i+1) * 100 * p + c #合計得点
    pc.append([p,c,tmp])

A = [0,1]
mintimes = 10000

for i in itertools.product(A,repeat=D):
    score = 0
    times = 0
    lest = []
    
    for j,v in enumerate(i):
        if v != 0:
            score += pc[j][2]
            times += pc[j][0]
        else:
            lest.append(j)
    
    if score >= G:
        #更新する
        mintimes = min(times,mintimes)
    else:
        objective = G - score

        part = []
        for k in lest: 
            part.append([pc[k][0],100*(k+1)])
        
        part2 = sorted(part,key=itemgetter(1),reverse = True)

        for m in part2:
            if objective > (m[0]-1) * m[1]:
                objective -= (m[0]-1) * m[1]
                times += (m[0]-1)
            else:
                tmp3 = objective // m[1]
                if objective % m[1] != 0:
                    tmp3 += 1
                times += tmp3
                mintimes = min(mintimes,times)
                break

print(mintimes)
