d,g = map(int,input().split())
p,c = [0]*d,[0]*d
import math

for i in range(d):
    p[i],c[i] = map(int,input().split())

ans = 10**9
for i in range(2**d):
    ls = ""
    for j in range(d):
        if (i>>j)&1:
            ls = "1"+ls
        else:
            ls = "0"+ls
    score = 0
    cnt = 0
    ls = list(ls)
    for i in range(d):
        if ls[(d-1)-i] == "1":
            score += 100*(i+1)*p[i] + c[i]
            cnt += p[i]
    if score>=g:
        ans = min(ans,cnt)
    else:
        index = d-1 - ls.index("0")
        maximum = p[index]
        score = g - score
        if maximum>=math.ceil(score/((index+1)*100)):
            cnt +=math.ceil(score/((index+1)*100))
            ans = min(ans,cnt)
        else:
            pass


print(ans)
