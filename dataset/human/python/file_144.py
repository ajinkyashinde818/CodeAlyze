R,G,B,N=(int(i) for i in input().split())
import math
answer=0
for r in range(0,math.floor(N/R)+1):
    for g in range(math.floor(N/G)+1):
        if R*r+G*g>N:
            break
        if (N-R*r-G*g)%B==0:
            answer+=1

print(answer)
