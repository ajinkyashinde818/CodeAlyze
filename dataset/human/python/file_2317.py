import math
D,G = map(int,input().split())
p=[]
c=[]
for i in range(D):
    p_tmp,c_tmp = map(int,input().split())
    p.append(p_tmp)
    c.append(c_tmp)

ans = sum(p)
for i in range(2**D):
    score_tmp = 0
    ans_tmp = 0
    for j in range(D):
        if (i>>j)%2 == 1:
            score_tmp += p[j]*(j+1)*100+c[j]
            ans_tmp += p[j]

    if ans_tmp >= ans:
        continue
    elif score_tmp >= G:
        ans = ans_tmp
        continue
    else:
        for j in range(D):
            if (i>>(D-1-j))%2 == 1:
                continue
            elif score_tmp + p[D-1-j]*(D-j)*100 < G:
                break
            else:
                ans_tmp += math.ceil((G - score_tmp)/((D-j)*100))
                ans = min(ans,ans_tmp)
                break

print(ans)
