import math
D, G = map(int,input().split())
S = [list(map(int,input().split())) for k in range(D)]

ans = 10**9+7
for k in range(1<<D):
    temp_score = 0
    solved = 0
    not_used = [k for k in range(D)]
    for l in range(D):
        if k&(1<<l):
            temp_score += 100*(l+1)*S[l][0] + S[l][1]
            not_used.remove(l)
            solved += S[l][0]
    if temp_score >= G:
        ans = min(ans,solved)
    else:
        if (not_used[-1]+1)*(S[not_used[-1]][0]-1)*100 + temp_score >= G:
            solved += math.ceil((G-temp_score)/((not_used[-1]+1)*100))
            ans = min(ans,solved)

print(ans)
