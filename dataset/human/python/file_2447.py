import sys,math,collections,itertools,copy
input = sys.stdin.readline

D,G=list(map(int,input().split()))
score = []
maxScore = []
maxS = []
for d in range(D):
    p,c=map(int,input().split())
    tmp = [(d+1)*100]*p
    tmp[-1]+=c
    score.append(tmp)
    maxScore.append(sum(tmp))
    maxS.append([p,sum(tmp)])

#-最大いくつの問題セットを必要とするか-#
maxScore.sort()
tmp = 0
for idx,mS in enumerate(maxScore):
    tmp += mS
    if tmp >= G:
        max_num = idx+1
        break
#-足し上げる-#
choice = set(range(1,D+1))
ans = float('inf')
for ch in itertools.permutations(choice,max_num):
    times = 0
    total = 0
    flag = 0
    for ci in ch:
        if total + maxS[ci-1][1] <G:
            total += maxS[ci-1][1]
            times += maxS[ci-1][0]
        else:
            for sc in score[ci-1]:
                total += sc
                times += 1
                if total >= G:
                    ans = min(ans,times)
                    falg = 1
                    break
    if flag ==1:
        break
print(ans)
