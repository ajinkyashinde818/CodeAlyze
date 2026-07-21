ranknum,goal = map(int,input().split())
probnum = [0]*ranknum
bonus = [0]*ranknum
compscore = [0]*ranknum

for i in range(ranknum):
    probnum[i],bonus[i] = map(int,input().split())
    compscore[i] = probnum[i]*100*(i+1)+bonus[i]

from itertools import product
from math import ceil

minprob = 1001

for c in product(range(2),repeat=ranknum):
    score = 0
    solvedprob = 0
    notcompedindex = -1

    for i in range(ranknum):    
        if c[i] == 1:
            score += compscore[i]
            solvedprob += probnum[i]
        else:
            notcompedindex = i
        
    if score < goal and score+100*(notcompedindex+1)*(probnum[notcompedindex]-1) >= goal:
        solvedprob += ceil((goal-score)/(100*(notcompedindex+1)))
        score += ceil((goal-score)/(100*(notcompedindex+1))) * (100*(notcompedindex+1))
    
    if score >= goal:
        minprob = min(minprob,solvedprob)

print(minprob)
