import math
D, G = map(int, input().split())

P = []; C = []
for i in range(D):
    pi, ci = map(int, input().split())
    P.append(pi)
    C.append(ci)

max_cnt = sum(P)

def solve(i, score, cnt, nm):
    if i == D:
        if score >= G:
            return cnt
        else:
            add_cnt = (G-score)/((nm+1)*100)
            if add_cnt > P[nm]:
                return max_cnt
            else:
                return cnt + int(math.ceil(add_cnt))
    return min([solve(i+1, score+P[i]*(i+1)*100 + C[i], cnt+P[i], nm), 
                solve(i+1, score, cnt, i)])

a = solve(0, 0, 0, 0)
print(a)
