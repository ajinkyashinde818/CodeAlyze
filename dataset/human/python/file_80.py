R,G,B,N=map(int,input().split())
import math
ans=0
a=math.floor(N/R)
for i in range(a+1):
    nokori=N-R*i
    b=math.floor(nokori/G)
    for j in range(b+1):
        nokori2=nokori-j*G
        if nokori2%B==0:
            ans+=1
        else:
            pass
print(ans)
