import math
D, G = list(map(int,input().split()))
P = [0]*D
C = [0]*D
for i in range(D):
    p,c = list(map(int,input().split()))
    P[i], C[i] = p, c

ans = float("inf")
for i in range(2**D):
    comp_list = [0]*D
    tmp_num = 0
    tmp_score = 0
    for j in range(D):
        if (i >> j) & 1:
            comp_list[j] = 1
            tmp_num += P[j]
            tmp_score += P[j]*(j+1)*100 + C[j]
    if tmp_score >= G:
        if tmp_num < ans:
            ans = tmp_num
    else:
        list_notcomp= [k for k in range(D) if comp_list[k] == 0]
        if len(list_notcomp) != 0:
            if math.ceil((G - tmp_score) / (100*(max(list_notcomp) + 1))) < P[max(list_notcomp)]:
                tmp_num += math.ceil((G - tmp_score) / (100*(max(list_notcomp) + 1)))
                if tmp_num < ans:
                    ans = tmp_num
print(ans)
