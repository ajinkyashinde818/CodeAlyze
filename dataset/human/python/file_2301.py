import math
D,G = map(int,input().split())
pc = list(list(map(int,input().split()))for i in range(D))
ans = float('inf')
for i in range(2**D):    
    score = 0
    AC = 0
    b = bin(2**D+i)[3:]
    for j in range(D):
        if b[j] == "1":
            score += pc[j][1]+pc[j][0]*(j+1)*100
            AC += pc[j][0]
        else:
            hoge = j
    if G <= score + pc[hoge][0]*(hoge+1)*100:
        a = max(0,math.ceil((G-score)/((hoge+1)*100)))
        score = G
        AC+= a
    if score >= G:
        ans = min(ans,AC)
print(ans)
