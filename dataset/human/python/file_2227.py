from itertools import *

D, G = map(int,input().split())

P = [None]*D
C = [None]*D

for i in range(D) :
    P[i], C[i] = map(int,input().split())

products = product(range(2), repeat=D)

ans = float("inf")

for prod in products :
    prod = list(prod)
    
    A = []
    
    cost = 0
    score = 0
    
    for i in range(len(prod)) :
        if prod[i] == 1 :
            A.append(i)
            cost += P[i]
            score += (i+1)*100*P[i]+C[i]
    
    if score < G :
        for i in range(len(prod)-1,-1,-1) :
            if prod[i] == 1 :
                continue
            
            if score + (i+1)*100*P[i] >= G :
                if G-score < 0 :
                    continue
                cost += (G-score)//((i+1)*100) + ((G-score) % ((i+1)*100) != 0)
                break
            
            else :
                cost += P[i]
                score += (i+1)*100*P[i]+C[i]
    
    ans = min(ans, cost)

print(ans)
